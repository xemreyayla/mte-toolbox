#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , logFile("logfile.txt")
{
    ui->setupUi(this);
    resizecomboBox();

    qApp->setStyleSheet(
        "QMessageBox QLabel { color: white; }"
        "QPushButton { color: white; }"
        "QLabel { color: white; }"
    );

    connect(ui->deviceinfoButton, &QPushButton::clicked, this, &MainWindow::showDeviceInfoPage);
    connect(ui->utilitiesButton, &QPushButton::clicked, this, &MainWindow::showUtilitiesPage);
    connect(ui->configurationButton, &QPushButton::clicked, this, &MainWindow::showConfigurationPage);
    connect(ui->connectionButton, &QPushButton::clicked, this, &MainWindow::showConnectionPage);
    connect(ui->consoleButton, &QPushButton::clicked, this, &MainWindow::showConsolePage);

    // 'returnPressed' sinyalini 'rwConsole' fonksiyonuna bağla
    connect(ui->consoleLineEdit, &QLineEdit::returnPressed, this, &MainWindow::rwConsole);

    connect(ui->sdFormatButton, &QPushButton::clicked, this, &MainWindow::sdFormatButton_clicked);
    connect(ui->connectportsButton, &QPushButton::clicked, this, &MainWindow::connectToDevice);
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::refreshPorts);
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

}

void MainWindow::showConfigurationPage() {
    logMessageToGuiAndFile("showConfigurationPage() called");
    qDebug() << "showConfigurationPage() called";
    ui->stackedWidget->setCurrentWidget(ui->ConfigurationPage);
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
        QMessageBox::critical(this, "Connection Error", "Failed to connect.\n" + errorMessage);
        return;
    }

    logMessageToGuiAndFile("Connected to serial port successfully.");
    QMessageBox::information(this, "Connection Successful", "Connected to " + selectedPortName + " successfully.");
    ui->connectionLabel->setText("Chipsee connection is active.");
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
    ui->consolePlainTextEdit->setReadOnly(true);
    // Gelen yanıtı UTF-8 olarak çöz ve ANSI kaçış kodlarını temizle
    QString response = QString::fromUtf8(responseData);
    QString cleanedResponse = cleanTerminalOutput(response);  // Temizlenmiş çıktıyı al

    // Komutu ve yanıtı consolePlainTextEdit'e ekle
    ui->consolePlainTextEdit->appendPlainText("root@linaro-alip:~# " + command);
    ui->consolePlainTextEdit->appendPlainText(cleanedResponse);

    ui->consoleLineEdit->clear();

    // Text cursor'ı en son mesaja kaydır
    QTextCursor cursor = ui->consolePlainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->consolePlainTextEdit->setTextCursor(cursor);

    // GUI güncellemelerinin hemen işlenmesini sağla
    QApplication::processEvents();
}
// Eklenen: JSON tamamlayıcı okuma fonksiyonu
QString MainWindow::readUntilJsonComplete(int overallTimeoutMs) {
    QByteArray buffer;
    QElapsedTimer timer;
    timer.start();

    int openBraces = 0;
    bool started = false;

    while (timer.elapsed() < overallTimeoutMs) {
        if (serialPort->waitForReadyRead(200)) {
            buffer += serialPort->readAll();

            for (char c : std::as_const(buffer)) {
                if (c == '{') {
                    openBraces++;
                    started = true;
                } else if (c == '}') {
                    openBraces--;
                }
            }

            if (started && openBraces == 0)
                break;
        }
    }

    return QString::fromUtf8(buffer).trimmed();
}

// Eklenen: JSON başarısızsa UI label'larına hata yazan yardımcı fonksiyon
void MainWindow::setIpLabelsError() {
    const QString err = "Unable to reach the IP adress.";
    ui->utestSerialLabel->setText(err);
    ui->utestProductLabel->setText(err);
    ui->appVersionLabel->setText(err);
    ui->chipseeSerialLabel->setText(err);
    ui->chipseeProductLabel->setText(err);
    ui->lastModifiedLabel->setText(err);
}

// Güncellenen: fetchIpData fonksiyonu
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
    const qint64 maxSize = 10 * 1024 * 1024; // 5MB

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


MainWindow::~MainWindow() {
    logMessageToGuiAndFile("MainWindow destroyed.");
    delete ui;
    if (serialPort){
        serialPort->close();
        delete serialPort;
    }
}
