#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , logFile("logfile.txt")//QFile nesnesi oluştur, log kayıtlarının dosyada tutulmasını sağlar
{
    ui->setupUi(this);//arayüzdeki tüm bileşenleri mainwindow içine yerleştir
    resizecomboBox();

    // Butonlara tıklanınca ilgili sayfalara geçiş yap
    connect(ui->deviceinfoButton, &QPushButton::clicked, this, &MainWindow::showDeviceInfoPage);
    connect(ui->utilitiesButton, &QPushButton::clicked, this, &MainWindow::showUtilitiesPage);
    connect(ui->configurationButton, &QPushButton::clicked, this, &MainWindow::showConfigurationPage);
    connect(ui->connectionButton, &QPushButton::clicked, this, &MainWindow::showConnectionPage);
    connect(ui->connectportsButton, &QPushButton::clicked, this, &MainWindow::connectToDevice);
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::refreshPorts);

    logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);// yazma modu, text formatında, append et
    logStream.setDevice(&logFile); //LogFile ile bağlantı kur


    refreshPorts();
}

void MainWindow::logMessageToGuiAndFile(const QString &msg){

    QString logMessage = QString("[DEBUG] [%1] %2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"),msg);
    ui->plainTextEdit->appendPlainText(logMessage);//guiye yazdır
    ui->plainTextEdit->setReadOnly(true); //Sadece okunabilir duruma getir
    logStream << logMessage << Qt::endl;
    logStream.flush();

}




void MainWindow::showConnectionPage(){
    qDebug() << "showConnectionPage() called";
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::showDeviceInfoPage() {
    qDebug() << "showDeviceInfoPage() called";
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::showUtilitiesPage() {
    qDebug() << "showUtilitiesPage() called";
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::showConfigurationPage() {
    qDebug() << "showConfigurationPage() called";
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::resizecomboBox(){
   QAbstractItemView *view = ui->serialportscomboBox->view();

   QApplication::setStyle("Windows");

   view->setMaximumHeight(200);
   view->setMinimumHeight(150);
   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void MainWindow::connectToDevice(){
    logMessageToGuiAndFile("connectToDevice() called");

    QString selectedPortName = ui->serialportscomboBox->currentText();
    logMessageToGuiAndFile("Selected Port: " + selectedPortName);

    if(selectedPortName.isEmpty() || selectedPortName == "No available ports"){
        logMessageToGuiAndFile("Error: Port not selected or unavailable");
        QMessageBox::warning(this, "Error", "Port not available or selected");
        return;
    }

    QSerialPort *serialPort = new QSerialPort(this);

    serialPort->setPortName(selectedPortName);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    logMessageToGuiAndFile("Serial port settings configured");



    if (!serialPort->open(QIODevice::ReadWrite)) {
        qInfo() << "Seri port açılamadı. Hata kodu: " << serialPort->error();

        QString errorMessage;
        switch (serialPort->error()) {
        case QSerialPort::NoError:
            errorMessage = "No error.";
            break;
        case QSerialPort::DeviceNotFoundError:
            errorMessage = "Device not found.";
            break;
        case QSerialPort::PermissionError:
            errorMessage = "Permission denied.";
            break;
        case QSerialPort::OpenError:
            errorMessage = "Unable to open the port.";
            break;
        case QSerialPort::WriteError:
            errorMessage = "Write error.";
            break;
        case QSerialPort::ReadError:
            errorMessage = "Read error.";
            break;
        case QSerialPort::ResourceError:
            errorMessage = "Resource error.";
            break;
        case QSerialPort::TimeoutError:
            errorMessage = "Timeout error.";
            break;
        case QSerialPort::UnknownError:
            errorMessage = "Unknown error.";
            break;
        default:
            errorMessage = "An unknown error occurred.";
            break;
        }

        logMessageToGuiAndFile("Error message: " + errorMessage);
        QMessageBox::critical(this, "Connection Error", "Failed to connect to the port.\n" + errorMessage);
        return;
    }

    logMessageToGuiAndFile("Connected to serial port successfully.");
    QMessageBox::information(this, "Connection Successful", "Connected to " + selectedPortName + " successfully.");
}


void MainWindow::refreshPorts(){
    logMessageToGuiAndFile("refreshPorts() called");

    QList<QString> portList;
    for (const QSerialPortInfo &port:QSerialPortInfo::availablePorts()){
    portList.append(port.portName());
    ui->serialportscomboBox->addItems(portList);
    logMessageToGuiAndFile("Port added to comboBox: " + port.portName());
    }

    if (portList.isEmpty()) {
        logMessageToGuiAndFile("No available ports found.");
        ui->serialportscomboBox->clear();
        ui->serialportscomboBox->addItem("No available ports");  // ComboBox'a hata mesajı ekle
    }
    else {
        // Eğer portList'te port varsa, ComboBox'ı temizle ve listeyi ekle
        logMessageToGuiAndFile("Available ports loaded");
        ui->serialportscomboBox->clear();
        ui->serialportscomboBox->addItems(portList);
    }


}


MainWindow::~MainWindow()
{
    delete ui;
}
