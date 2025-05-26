#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "version.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , logFile("logfile.txt")
{
    ui->setupUi(this);
    resizecomboBox();
    statusBar()->showMessage(QString("Version: %1").arg(MTE_TOOLBOX_VERSION));

    qApp->setStyleSheet(
        "QMessageBox QLabel { color: white; }"
        "QPushButton { color: white; }"
        "QLabel { color: white; }"
    );

    connect(ui->deviceinfoButton, &QPushButton::clicked, this, &MainWindow::showDeviceInfoPage);
    connect(ui->utilitiesButton, &QPushButton::clicked, this, &MainWindow::showUtilitiesPage);
    connect(ui->connectionButton, &QPushButton::clicked, this, &MainWindow::showConnectionPage);
    connect(ui->consoleButton, &QPushButton::clicked, this, &MainWindow::showConsolePage);

    // 'returnPressed' sinyalini 'rwConsole' fonksiyonuna bağla
    connect(ui->consoleLineEdit, &QLineEdit::returnPressed, this, &MainWindow::rwConsole);

    connect(ui->sdFormatButton, &QPushButton::clicked, this, &MainWindow::sdFormatButton_clicked);
    connect(ui->connectportsButton, &QPushButton::clicked, this, &MainWindow::connectToDevice);
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::refreshPorts);
    connect(ui->disconnectButton, &QPushButton::clicked, this, &MainWindow::disconnectFromDevice);

    //utilities lowButtons
    connect(ui->out1LowButton, &QPushButton::clicked, this, &MainWindow::setOutputButtons);
    connect(ui->out2LowButton, &QPushButton::clicked, this, &MainWindow::setOutputButtons);
    connect(ui->out3LowButton, &QPushButton::clicked, this, &MainWindow::setOutputButtons);
    connect(ui->out4LowButton, &QPushButton::clicked, this, &MainWindow::setOutputButtons);
    //utilities highButtons
    connect(ui->out1HighButton, &QPushButton::clicked, this, &MainWindow::setOutputButtons);
    connect(ui->out2HighButton, &QPushButton::clicked, this, &MainWindow::setOutputButtons);
    connect(ui->out3HighButton, &QPushButton::clicked, this, &MainWindow::setOutputButtons);
    connect(ui->out4HighButton, &QPushButton::clicked, this, &MainWindow::setOutputButtons);
    //utilities get first status
    connect(ui->getFirstStatusButton, &QPushButton::clicked, this, &MainWindow::getFirstStatusButton_clicked);

    logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    logStream.setDevice(&logFile);

    refreshPorts();
    logMessageToGuiAndFile("MainWindow initialized.");
}


void MainWindow::logMessageToGuiAndFile(const QString &msg){
    QString logMessage = QString("[DEBUG] [%1] %2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"),msg);
    ui->plainTextEdit->appendPlainText(logMessage);
    ui->plainTextEdit->setReadOnly(true);
    if (ui->plainTextEdit->document()->blockCount() > 15000){
        ui->plainTextEdit->clear();
    }
    logStream << logMessage << Qt::endl;
    logStream.flush();
}

void MainWindow::showConnectionPage(){
    logMessageToGuiAndFile("showConnectionPage() called");
    qDebug() << "showConnectionPage() called";
    ui->stackedWidget->setCurrentWidget(ui->ConnectionPage);
}

void MainWindow::showDeviceInfoPage() {
    logMessageToGuiAndFile("showDeviceInfoPage() called");
    qDebug() << "showDeviceInfoPage() called";

    QProgressDialog progress("Fetching device information...", nullptr, 0, 0, this);
    progress.setWindowModality(Qt::ApplicationModal);
    progress.setCancelButton(nullptr);
    progress.setWindowTitle("Please Wait");
    progress.setMinimumDuration(0);
    progress.show();
    QApplication::processEvents(); //UI refresh

    ui->stackedWidget->setCurrentWidget(ui->DeviceInfoPage);

    if (!firstTimeDeviceInfoShown) {
        // Sadece ikinci ve sonraki tıklamalarda temizle
        ui->osLabel->clear();
        ui->kernelnOLabel->clear();
        ui->nodenOLabel->clear();
        ui->kernelvOLabel->clear();
        ui->machinehOLabel->clear();
        ui->hardwarepOlabel->clear();
        ui->kernelrOLabel->clear();
        ui->prettyNameLabel->clear();
        ui->versionLabel->clear();
        ui->buildInfoPlainTextEdit->clear();
        ui->plainTextEdit->clear();
    }

    firstTimeDeviceInfoShown = false;
    fetchOSInfo();
    fetchIpData();
    readData();
}

void MainWindow::showUtilitiesPage() {
    logMessageToGuiAndFile("showUtilitiesPage() called");
    qDebug() << "showUtilitiesPage() called";
    ui->stackedWidget->setCurrentWidget(ui->UtilitiesPage);
    setOutputButtons();
}
void MainWindow::showConsolePage(){
    logMessageToGuiAndFile("showConsolePage() called");
    qDebug() << "showConsolePage() called";
    ui->stackedWidget->setCurrentWidget(ui->ConsolePage);
    rwConsole();
}
void MainWindow::resizecomboBox(){
    logMessageToGuiAndFile("resizecomboBox() called");
    QAbstractItemView *view = ui->serialportscomboBox->view();
    QApplication::setStyle("Windows");
    view->setMaximumHeight(200);
    view->setMinimumHeight(150);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void MainWindow::connectToDevice() {
    logMessageToGuiAndFile("connectToDevice() called");

    if (!serialPort) {
        serialPort = new QSerialPort(this);
    }

    QString selectedPortName = ui->serialportscomboBox->currentText();
    logMessageToGuiAndFile("Selected Port: " + selectedPortName);

    if (selectedPortName.isEmpty() || selectedPortName == "No available ports") {
        logMessageToGuiAndFile("Error: Port not selected or unavailable");
        QMessageBox::warning(this, "Error", "Port not available or selected");
        return;
    }else{
        ui->connectionLabel->setText("Chipsee connection is not available.");
    }

    serialPort = new QSerialPort(this);
    serialPort->setPortName(selectedPortName);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    logMessageToGuiAndFile("Serial port settings configured");



    if (!serialPort->open(QIODevice::ReadWrite)) {

        QString errorMessage;
        switch (serialPort->error()) {
        case QSerialPort::DeviceNotFoundError: errorMessage = "Device not found."; break;
        case QSerialPort::PermissionError: errorMessage = "Permission denied."; break;
        case QSerialPort::OpenError: errorMessage = "Unable to open the port."; break;
        case QSerialPort::WriteError: errorMessage = "Write error."; break;
        case QSerialPort::ReadError: errorMessage = "Read error."; break;
        case QSerialPort::ResourceError: errorMessage = "Resource error."; break;
        case QSerialPort::TimeoutError: errorMessage = "Timeout error."; break;
        default: errorMessage = "Unknown error."; break;
        }
        logMessageToGuiAndFile("Error message: " + errorMessage);
        logMessageToGuiAndFile("Detailed error: " + serialPort->errorString());
        QMessageBox::critical(this, "Connection Error", "Failed to connect.\n" + errorMessage);
        return;

    }


    logMessageToGuiAndFile("Connected to serial port successfully.");
    QMessageBox::information(this, "Connection Successful", "Connected to " + selectedPortName + " successfully.");
    ui->connectionLabel->setText("Chipsee connection is active.");
}

void MainWindow::disconnectFromDevice(){
    logMessageToGuiAndFile("disconnectFromDevice() called");

    if (serialPort){
        if (serialPort->isOpen()){
            serialPort->close();
            logMessageToGuiAndFile("Serial port closed.");
        }
        delete serialPort;
        serialPort = nullptr;
        logMessageToGuiAndFile("Serial port deleted");
    }
    ui->connectionLabel->setText("No device connected.");
    QMessageBox::information(this, "Disconnected", "Serial port disconnected.");
}

void MainWindow::readData() {
    logMessageToGuiAndFile("readData() called");

    if (!serialPort || !serialPort->isOpen()) {
        logMessageToGuiAndFile("Error: Serial port is not open.");
        return;
    }

    QString command = "cat /etc/os-release\n";
    serialPort->write(command.toUtf8());

    if (!serialPort->waitForBytesWritten(200)) {
        logMessageToGuiAndFile("Error: Command write timeout.");
        return;
    }

    QByteArray responseData;
    while (serialPort->waitForReadyRead(350)) {
        responseData.append(serialPort->readAll());
    }

    if (responseData.isEmpty()) {
        logMessageToGuiAndFile("Error: No data received.");
        return;
    }

    qDebug() << "Response Data: " << QString::fromUtf8(responseData);  // Yanıtı kontrol et

    QString osInfo = QString::fromUtf8(responseData).trimmed();
    qDebug() << "Parsed osInfo: " << osInfo;  // `osInfo` verisini kontrol et

    static const QRegularExpression re_pretty(R"(PRETTY_NAME=\"([^\"]+)\".*)");
    static const QRegularExpression re_name(R"(NAME=\"([^\"]+)\".*)");
    static const QRegularExpression re_version(R"(VERSION=\"([^\"]+)\".*)");
    static const QRegularExpression re_build(R"(BUILD_[A-Z_]+[ ]*=\"?([^\"]+)\"?)");

    QString prettyName, name, version, buildInfo;
    QRegularExpressionMatch match;

    // PRETTY_NAME, NAME, VERSION bilgilerini çekme
    if ((match = re_pretty.match(osInfo)).hasMatch()) {
        prettyName = match.captured(1);
    }

    if ((match = re_name.match(osInfo)).hasMatch()) {
        name = match.captured(1);
    }

    if ((match = re_version.match(osInfo)).hasMatch()) {
        version = match.captured(1);
    }

    // BUILD bilgilerini çekme
    QStringList buildList;
    QRegularExpressionMatchIterator it = re_build.globalMatch(osInfo);
    while (it.hasNext()) {
        buildList.append(it.next().captured(1));
    }
    buildInfo = buildList.join("\n");

    ui->plainTextEdit->setReadOnly(true);
    ui->buildInfoPlainTextEdit->setReadOnly(true);

    logMessageToGuiAndFile("OS Info:\n" + prettyName + "\n" + name + "\n" + version + "\n" + buildInfo);

    ui->prettyNameLabel->setText(prettyName.isEmpty() ? "Unknown OS" : prettyName);
    ui->versionLabel->setText(version.isEmpty() ? "Unknown Version" : version);

    ui->plainTextEdit->setPlainText(osInfo);  // osInfo'yu ekle
    ui->buildInfoPlainTextEdit->appendPlainText(buildInfo);  // Build bilgilerini ekle
}

void MainWindow::fetchOSInfo() {
    logMessageToGuiAndFile("fetchOSInfo() called");

    if (!serialPort || !serialPort->isOpen()) {
        logMessageToGuiAndFile("Error: Serial port is not open.");
        return;
    }

    QStringList commands = {
        "uname -o\n", "uname -s\n", "uname -n\n", "uname -v\n",
        "uname -m\n", "uname -i\n", "uname -r\n"
    };

    QStringList results;

    for (const QString& command : commands) {
        serialPort->readAll(); // Önceki buffer'ı temizle
        serialPort->write(command.toUtf8());

        if (!serialPort->waitForBytesWritten(100)) {
            logMessageToGuiAndFile("Error: Command write timeout for: " + command);
            return;
        }

        QByteArray responseData;
        QElapsedTimer timer;
        timer.start();
        const int timeout = 100;

        while (timer.elapsed() < timeout) {
            if (serialPort->waitForReadyRead(150)) {
                responseData.append(serialPort->readAll());
            }
        }

        if (responseData.isEmpty()) {
            logMessageToGuiAndFile("Error: No data received for command: " + command);
            results.append("Unknown");
            continue;
        }

        QString info = QString::fromUtf8(responseData).trimmed();
        info.remove(QRegularExpression("\\x1B\\[[0-9;?]*[a-zA-Z]"));
        info.remove(QRegularExpression(".*@.*:~#"));

        QStringList lines = info.split("\n", Qt::SkipEmptyParts);
        results.append(!lines.isEmpty() ? lines.last().trimmed() : "Unknown");
    }

    logMessageToGuiAndFile("Operating System: " + results[0]);
    logMessageToGuiAndFile("Kernel Name: " + results[1]);
    logMessageToGuiAndFile("Host Name: " + results[2]);
    logMessageToGuiAndFile("Kernel Version: " + results[3]);
    logMessageToGuiAndFile("Machine Hardware: " + results[4]);
    logMessageToGuiAndFile("Hardware Platform: " + results[5]);
    logMessageToGuiAndFile("Kernel Release: " + results[6]);

    ui->osLabel->setText(results[0]);
    ui->kernelnOLabel->setText(results[1]);
    ui->nodenOLabel->setText(results[2]);
    ui->kernelvOLabel->setText(results[3]);
    ui->machinehOLabel->setText(results[4]);
    ui->hardwarepOlabel->setText(results[5]);
    ui->kernelrOLabel->setText(results[6]);
}

void MainWindow::refreshPorts(){
    logMessageToGuiAndFile("refreshPorts() called");

    QList<QString> portList;
    for (const QSerialPortInfo &port:QSerialPortInfo::availablePorts()){
        portList.append(port.portName());
        logMessageToGuiAndFile("Port added to comboBox: " + port.portName());
    }

    ui->serialportscomboBox->clear();

    if (portList.isEmpty()) {
        logMessageToGuiAndFile("No available ports found.");
        ui->serialportscomboBox->addItem("No available ports");
    } else {
        logMessageToGuiAndFile("Available ports loaded");
        ui->serialportscomboBox->addItems(portList);
    }
}

void MainWindow::rwConsole() {
    logMessageToGuiAndFile("rwConsole() called");
    ui->consolePlainTextEdit->setReadOnly(true);

    if (!serialPort || !serialPort->isOpen()) {
        logMessageToGuiAndFile("Error: Serial port is not open.");
        QMessageBox::critical(this, "Error", "Serial port is not open. Please set up the serial port first. ");
        return;
    }

    QString command = ui->consoleLineEdit->text(); // Kullanıcının girdiği komut

    if (command.isEmpty()) {
        logMessageToGuiAndFile("Error: No command entered.");
        return;
    }

    // Komutu cihazına gönder
    serialPort->write(command.toUtf8() + "\r\n");

    if (!serialPort->waitForBytesWritten(100)) {
        logMessageToGuiAndFile("Error: Command write timeout.");
        return;
    }

    QByteArray responseData;
    while (serialPort->waitForReadyRead(150)) {
        responseData.append(serialPort->readAll());
    }

    if (responseData.isEmpty()) {
        logMessageToGuiAndFile("Error: No data received.");
        return;
    }

    // Gelen yanıtı UTF-8 olarak çöz ve ANSI kaçış kodlarını temizle
    QString response = QString::fromUtf8(responseData);
    QString cleanedResponse = cleanTerminalOutput(response);  // Temizlenmiş çıktıyı al

    // Komutu ve yanıtı consolePlainTextEdit'e ekle
    ui->consolePlainTextEdit->appendPlainText("root@linaro-alip:~# " + command);
    ui->consolePlainTextEdit->appendPlainText(cleanedResponse);

    if (command == "clear"){
        ui->consolePlainTextEdit->clear();
        logMessageToGuiAndFile("Console cleadred by user.");
    }
    ui->consoleLineEdit->clear();

    // Text cursor'ı en son mesaja kaydır
    QTextCursor cursor = ui->consolePlainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->consolePlainTextEdit->setTextCursor(cursor);

    // GUI güncellemelerinin hemen işlenmesini sağla
    QApplication::processEvents();
}

QString MainWindow::readUntilJsonComplete(int overallTimeoutMs) {
    QByteArray buffer;
    QElapsedTimer timer;
    timer.start();

    int openBraces = 0;
    bool started = false;

    logMessageToGuiAndFile("readUntilJsonComplete() started. Timeout: " + QString::number(overallTimeoutMs) + "ms");

    while (timer.elapsed() < overallTimeoutMs) {
        if (serialPort->waitForReadyRead(200)) {
            QByteArray chunk = serialPort->readAll();
            buffer += chunk;

            logMessageToGuiAndFile("Read chunk: " + QString::fromUtf8(chunk));

            for (char c : std::as_const(buffer)) {
                if (c == '{') {
                    openBraces++;
                    started = true;
                } else if (c == '}') {
                    openBraces--;
                }
            }

            if (started && openBraces == 0) {
                logMessageToGuiAndFile("Complete JSON received.");
                break;
            }
        }
    }

    if (!started || openBraces != 0) {
        logMessageToGuiAndFile("Warning: JSON may be incomplete. Timeout or mismatched braces.");
    }

    return QString::fromUtf8(buffer).trimmed();
}

void MainWindow::setIpLabelsError() {
    const QString err = "Unable to access the files.";
    ui->utestSerialLabel->setText(err);
    ui->utestProductLabel->setText(err);
    ui->appVersionLabel->setText(err);
    ui->chipseeSerialLabel->setText(err);
    ui->chipseeProductLabel->setText(err);
    ui->lastModifiedLabel->setText(err);
}

void MainWindow::fetchIpData() {
    logMessageToGuiAndFile("fetchIpData() called");

    if (!serialPort || !serialPort->isOpen()) {
        logMessageToGuiAndFile("Error: Serial port is not open.");
        setIpLabelsError();
        return;
    }

    QString commandFetch = "cat /etc/mte/system_config.json\n";
    serialPort->write(commandFetch.toUtf8());

    if (!serialPort->waitForBytesWritten(150)) {
        logMessageToGuiAndFile("Error: Command write timeout.");
        setIpLabelsError();
        return;
    }

    QString jsonString = readUntilJsonComplete(3500);
    logMessageToGuiAndFile("Raw JSON (maybe messy):\n" + jsonString);

    int startIndex = jsonString.indexOf('{');
    int endIndex = jsonString.lastIndexOf('}');
    if (startIndex == -1 || endIndex == -1 || endIndex <= startIndex) {
        logMessageToGuiAndFile("Error: JSON boundaries not found.");
        setIpLabelsError();
        return;
    }

    jsonString = jsonString.mid(startIndex, endIndex - startIndex + 1);
    logMessageToGuiAndFile("Cleaned JSON:\n" + jsonString);

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        logMessageToGuiAndFile("JSON parse error: " + parseError.errorString());
        setIpLabelsError();
        return;
    }

    if (!jsonDoc.isObject()) {
        logMessageToGuiAndFile("Error: JSON is not an object.");
        setIpLabelsError();
        return;
    }

    QJsonObject obj = jsonDoc.object();

    QString utestSerial = obj.value("utest_serial_number").toString();
    QString utestProduct = obj.value("utest_product_number").toString();
    QString urepoVersion = obj.value("urepo_application_version").toString();
    QString chipseeSerial = obj.value("chipsee_serial_number").toString();
    QString chipseeProduct = obj.value("chipsee_product_number").toString();
    qint64 lastModifiedUnix = obj.value("last_modified").toVariant().toLongLong();
    QString lastModified = QDateTime::fromSecsSinceEpoch(lastModifiedUnix).toString("yyyy-MM-dd hh:mm:ss");

    logMessageToGuiAndFile("Utest Serial: " + utestSerial);
    logMessageToGuiAndFile("Utest Product: " + utestProduct);
    logMessageToGuiAndFile("Urepo Version: " + urepoVersion);
    logMessageToGuiAndFile("Chipsee Serial: " + chipseeSerial);
    logMessageToGuiAndFile("Chipsee Product: " + chipseeProduct);
    logMessageToGuiAndFile("Last Modified: " + lastModified);

    ui->utestSerialLabel->setText(utestSerial);
    ui->utestProductLabel->setText(utestProduct);
    ui->appVersionLabel->setText(urepoVersion);
    ui->chipseeSerialLabel->setText(chipseeSerial);
    ui->chipseeProductLabel->setText(chipseeProduct);
    ui->lastModifiedLabel->setText(lastModified);
    logMessageToGuiAndFile("Received JSON:\n" + jsonString);
}

QString MainWindow::removeAnsi(const QString &input) {
    QRegularExpression ansiRegex("\x1B\\[[0-9;?]*[ -/]*[@-~]");
    QString cleaned = input;
    cleaned.replace(ansiRegex, "");
    return cleaned;
}

QString MainWindow::cleanTerminalOutput(const QString &input) {
    return removeAnsi(input).trimmed();
}

void MainWindow::sdFormatButton_clicked(){
    logMessageToGuiAndFile("sdFormatButton_clicked() called");
    if (!serialPort || !serialPort->isOpen()) {
        logMessageToGuiAndFile("Error: Serial port is not open.");
        QMessageBox::critical(this, "Error", "Serial port is not open. Please set up the serial port first. ");
        return;
    }

    // Eğer az önce formatlandıysa, kullanıcıyı uyar
    if (sdCardFormattedRecently) {
        ui->formatLabel->setText("The SD card has already been formatted recently.\nThere is no need to format it again.");
        logMessageToGuiAndFile("User attempted to format again, but it was already recently formatted.");
        return;
    }

    // Serial port kontrolü
    if (!serialPort || !serialPort->isOpen()){
        ui->formatLabel->setText("Serial port is not open.");
        logMessageToGuiAndFile("Error: Serial port is not open.");
        return;
    }

    QString umountCommand = "umount /dev/mmcblk1p1\r\n";
    QString formatCommand = "mkfs.vfat -F 32 -n FORMATTEDSD /dev/mmcblk1p1\r\n";

    int bytesWritten = serialPort->write(umountCommand.toUtf8() + "\r\n");
    if (bytesWritten == -1) {
        logMessageToGuiAndFile("Error: Failed to write umount command.");
        ui->formatLabel->setText("Failed to send unmount command.");
        return;
    }

    QThread::msleep(350); // opsiyonel gecikme

    bytesWritten = serialPort->write(formatCommand.toUtf8() + "\r\n");
    if (bytesWritten == -1) {
        logMessageToGuiAndFile("Error: Failed to write format command.");
        ui->formatLabel->setText("Failed to send format command.");
        return;
    }

    ui->formatLabel->setText("SD Card formatted successfully at FAT32.");
    serialPort->write("echo 1 > /dev/buzzer\r\n");
    QTimer::singleShot(750, this, [this]() {
        if (serialPort && serialPort->isOpen()) {
            serialPort->write("echo 0 > /dev/buzzer\r\n");
            logMessageToGuiAndFile("Buzzer closed (750ms later).");
        }
    });
    logMessageToGuiAndFile("Information: SD Card formatted successfuly at FAT32.");


    // Durum değişkenini güncelle
    sdCardFormattedRecently = true;
    QTimer::singleShot(10000, this, [this]() {
        sdCardFormattedRecently = false;
        logMessageToGuiAndFile("Reset: SD card format flag cleared after timeout.");
    });
}

void MainWindow::rotateLogFileIfNeeded() {
    QFileInfo info("logfile.txt");
    const qint64 maxSize = 10 * 1024 * 1024; // 10MB

    if (!info.exists() || info.size() < maxSize) return;

    QString backup2 = "logfile.txt.2";
    QString backup1 = "logfile.txt.1";

    if (QFile::exists(backup2)) QFile::remove(backup2);
    if (QFile::exists(backup1)) QFile::rename(backup1, backup2);
    if (QFile::exists("logfile.txt")) QFile::rename("logfile.txt", backup1);

    logFile.close(); // Dosya açık olabilir, kapatıyoruz
    logFile.setFileName("logfile.txt");
    logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    logStream.setDevice(&logFile);
}

void MainWindow::setOutputButtons() {
    if (!serialPort || !serialPort->isOpen()) {
        QMessageBox::warning(this, "Connection Required", "A serial port connection is required. Please connect the serial port.");
        return;
    }
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString name = button->objectName();

    if (name == "out1LowButton") {
        QString lowCommand1 = "echo 0 > /dev/chipsee-gpio1\r\n";
        int bytesWritten = serialPort->write(lowCommand1.toUtf8());
        if (bytesWritten == -1) {
            qDebug() << "Failed to write data: out1LowButton";
        } else {
            qDebug() << name << "inactive";
            ui->out1Label->setText("0");
        }
    }
    else if (name == "out2LowButton") {
        QString lowCommand2 = "echo 0 > /dev/chipsee-gpio2\r\n";
        int bytesWritten = serialPort->write(lowCommand2.toUtf8());
        if (bytesWritten == -1) {
            qDebug() << "Failed to write data: out2LowButton";
        } else {
            qDebug() << name << "inactive";
            ui->out2Label->setText("0");
        }
    }
    else if (name == "out3LowButton") {
        QString lowCommand3 = "echo 0 > /dev/chipsee-gpio3\r\n";
        int bytesWritten = serialPort->write(lowCommand3.toUtf8());
        if (bytesWritten == -1) {
            qDebug() << "Failed to write data: out3LowButton";
        } else {
            qDebug() << name << "inactive";
            ui->out3Label->setText("0");
        }
    }
    else if (name == "out4LowButton") {
        QString lowCommand4 = "echo 0 > /dev/chipsee-gpio4\r\n";
        int bytesWritten = serialPort->write(lowCommand4.toUtf8());
        if (bytesWritten == -1) {
            qDebug() << "Failed to write data: out4LowButton";
        } else {
            qDebug() << name << "inactive";
            ui->out4Label->setText("0");
        }
    }

    if (name == "out1HighButton") {
        QString highCommand1 = "echo 1 > /dev/chipsee-gpio1\r\n";
        int bytesWritten = serialPort->write(highCommand1.toUtf8());
        if (bytesWritten == -1) {
            qDebug() << "Failed to write data: out1HighButton";
        } else {
            qDebug() << name << "active";
            ui->out1Label->setText("1");
        }
    }
    else if (name == "out2HighButton") {
        QString highCommand2 = "echo 1 > /dev/chipsee-gpio2\r\n";
        int bytesWritten = serialPort->write(highCommand2.toUtf8());
        if (bytesWritten == -1) {
            qDebug() << "Failed to write data: out2HighButton";
        } else {
            qDebug() << name << "active";
            ui->out2Label->setText("1");
        }
    }
    else if (name == "out3HighButton") {
        QString highCommand3 = "echo 1 > /dev/chipsee-gpio3\r\n";
        int bytesWritten = serialPort->write(highCommand3.toUtf8());
        if (bytesWritten == -1) {
            qDebug() << "Failed to write data: out3HighButton";
        } else {
            qDebug() << name << "active";
            ui->out3Label->setText("1");
        }
    }
    else if (name == "out4HighButton") {
        QString highCommand4 = "echo 1 > /dev/chipsee-gpio4\r\n";
        int bytesWritten = serialPort->write(highCommand4.toUtf8());
        if (bytesWritten == -1) {
            qDebug() << "Failed to write data: out4HighButton";
        } else {
            qDebug() << name << "active";
            ui->out4Label->setText("1");
        }
    }
}

/////////////////////////////////////////////////////////

void MainWindow::readGPIOStatus(int gpioNumber) {
    if (!serialPort || !serialPort->isOpen()) {
        logMessageToGuiAndFile("Error: Serial port not open.");
        return;
    }
    QString command = QString("cat /dev/chipsee-gpio%1\n").arg(gpioNumber);
    serialPort->write(command.toUtf8());
    qDebug() << "Command sent:" << command.trimmed();
}

void MainWindow::handleReadyRead() {
    serialBuffer.append(serialPort->readAll());
    qDebug() << "Current Buffer: " << QString::fromUtf8(serialBuffer);

    while (serialBuffer.contains("root@linaro-alip:~#")) {
        int promptIndex = serialBuffer.indexOf("root@linaro-alip:~#");
        QByteArray segmentToProcess = serialBuffer.left(promptIndex + QString("root@linaro-alip:~#").length());

        QString output = QString::fromUtf8(segmentToProcess);
        qDebug() << "Processing segment: " << output;

        QRegularExpression commandRegex("cat /dev/chipsee-gpio(\\d+)\\r\\n");
        QRegularExpressionMatch commandMatch = commandRegex.match(output);

        int processedGpioNumber = -1;

        if (commandMatch.hasMatch()) {
            processedGpioNumber = commandMatch.captured(1).toInt();
            qDebug() << "Identified GPIO command for:" << processedGpioNumber;

            // Regex to find the status (\r0\r\n or \r1\r\n) after the command echo
            QRegularExpression statusRegex("\\r(0|1)\\r\\n");
            // Search for the status starting from the end of the command echo in the full segment
            QRegularExpressionMatch statusMatch = statusRegex.match(output, commandMatch.capturedEnd());

            if (statusMatch.hasMatch()) {
                QString status = statusMatch.captured(1);
                QString statusText = (status == "0") ? "LOW" : "HIGH";

                qDebug() << "Status found for GPIO " << processedGpioNumber << ": " << statusText;


                switch (processedGpioNumber) {
                case 1:
                    if (ui->out1Label) {
                        ui->out1Label->setText(statusText);
                    }
                    break;
                case 2:
                    if (ui->out2Label) {
                        ui->out2Label->setText(statusText);
                    }
                    break;
                case 3:
                    if (ui->out3Label) {
                        ui->out3Label->setText(statusText);
                    }
                    break;
                case 4:
                    if (ui->out4Label) {
                        ui->out4Label->setText(statusText);
                    }
                    break;
                case 5:
                    if (ui->in1Label) {
                        ui->in1Label->setText(statusText);
                    }
                    break;
                case 6:
                    if (ui->in2Label) {
                        ui->in2Label->setText(statusText);
                    }
                    break;
                case 7:
                    if (ui->in3Label) {
                        ui->in3Label->setText(statusText);
                    }
                    break;
                case 8:
                    if (ui->in4Label) {
                        ui->in4Label->setText(statusText);
                    }
                    break;
                default:
                    qDebug() << "Received status for unexpected GPIO number:" << processedGpioNumber;
                    break;
                }
                logMessageToGuiAndFile(QString("GPIO %1 Status: %2").arg(processedGpioNumber).arg(statusText));

            } else {
                qDebug() << "Status pattern (\\r0\\r\\n or \\r1\\r\\n) not found after command for GPIO" << processedGpioNumber;
                logMessageToGuiAndFile(QString("Could not determine status for GPIO %1. Segment: %2").arg(processedGpioNumber).arg(output.trimmed()));

                switch (processedGpioNumber) {
                case 5:
                    if (ui->in1Label) {
                        ui->in1Label->setText("Status not found");
                    }
                    break;
                case 6:
                    if (ui->in2Label) {
                        ui->in2Label->setText("Status not found");
                    }
                    break;
                case 7:
                    if (ui->in3Label) {
                        ui->in3Label->setText("Status not found");
                    }
                    break;
                case 8:
                    if (ui->in4Label) {
                        ui->in4Label->setText("Status not found");
                    }
                    break;
                default:
                    break;
                }
            }
        } else {
            qDebug() << "No identifiable GPIO command found in segment ending with prompt.";
            logMessageToGuiAndFile(QString("Processed segment does not contain an expected GPIO command: %1").arg(output.trimmed()));
        }
        serialBuffer.remove(0, segmentToProcess.length());
        qDebug() << "Buffer after processing segment: " << QString::fromUtf8(serialBuffer);
    }
}

void MainWindow::getFirstStatusButton_clicked() {
    if (!serialPort || !serialPort->isOpen()) {
        logMessageToGuiAndFile("Error: Serial port is not open.");
        QMessageBox::critical(this, "Error", "Serial port is not open. Please set up the serial port first. ");
        return;
    }
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::handleReadyRead);
    readGPIOStatus(1);
    QTimer::singleShot(400, this, [=]() { readGPIOStatus(2); });
    QTimer::singleShot(800, this, [=]() { readGPIOStatus(3); });
    QTimer::singleShot(1200, this, [=]() { readGPIOStatus(4); });
    QTimer::singleShot(1600, this, [=]() { readGPIOStatus(5); });
    QTimer::singleShot(2000, this, [=]() { readGPIOStatus(6); });
    QTimer::singleShot(2400, this, [=]() { readGPIOStatus(7); });
    QTimer::singleShot(2800, this, [=]() { readGPIOStatus(8); });
}

MainWindow::~MainWindow() {
    logMessageToGuiAndFile("MainWindow destroyed.");
    delete ui;
    if (serialPort != nullptr){
        if(serialPort->isOpen()){
            serialPort->close();
        }
        delete serialPort;
        serialPort = nullptr;
    }
    delete ui;
}
