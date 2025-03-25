#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Butonlara tıklanınca ilgili sayfalara geçiş yap
    connect(ui->deviceinfoButton, &QPushButton::clicked, this, &MainWindow::showDeviceInfoPage);
    connect(ui->utilitiesButton, &QPushButton::clicked, this, &MainWindow::showUtilitiesPage);
    connect(ui->configurationButton, &QPushButton::clicked, this, &MainWindow::showConfigurationPage);
    connect(ui->connectionButton, &QPushButton::clicked, this, &MainWindow::showConnectionPage);


    connect(ui->connectportsButton, &QPushButton::clicked, this, &MainWindow::connectToDevice);
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::refreshPorts);

    refreshPorts();


}

void MainWindow::showDeviceInfoPage() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::showUtilitiesPage() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::showConfigurationPage() {
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::showConnectionPage(){
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::resizecomboBox(){
   QAbstractItemView *view = ui->serialportscomboBox->view();

   view->setMaximumHeight(50);
   view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

}

void MainWindow::connectToDevice(){
    QString selectedPortName = ui->serialportscomboBox->currentText();

    if(selectedPortName.isEmpty() || selectedPortName == "No available ports"){
        QMessageBox::warning(this, "Eror, try again!","This is the warning message");
        return;


    }

    QSerialPort *serialPort = new QSerialPort(this);

    serialPort->setPortName(selectedPortName);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);



    if (!serialPort->open(QIODevice::ReadWrite)) {
        // Bağlantı hatası durumunda
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

        QMessageBox::critical(this, "Connection Error", "Failed to connect to the port.\n" + errorMessage);
        return;
    }

    // Eğer bağlantı başarılıysa
    QMessageBox::information(this, "Connection Successful", "Connected to " + selectedPortName + " successfully.");
}
    /*if (serialPort->open(QIODevice::ReadOnly)){
        QMessageBox::information(this, "Connection successful","Connection successful!");

    }
    else {
        QMessageBox::critical(this, "Connection error", "Error!");
    }


}*/


void MainWindow::refreshPorts(){
    QList<QString> portList;
    for (const QSerialPortInfo &port:QSerialPortInfo::availablePorts()){
    portList.append(port.portName());
    ui->serialportscomboBox->addItems(portList);
    }

    if (portList.isEmpty()) {
        ui->serialportscomboBox->clear();
        ui->serialportscomboBox->addItem("No available ports");  // ComboBox'a hata mesajı ekle
    }
    else {
        // Eğer portList'te port varsa, ComboBox'ı temizle ve listeyi ekle
        ui->serialportscomboBox->clear();
        ui->serialportscomboBox->addItems(portList);
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}
