#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QList>
#include <QtLogging>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QApplication>
/*#include <QByteArray>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>*/


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showDeviceInfoPage();
    void showUtilitiesPage();
    void showConfigurationPage();
    void showConnectionPage();
    void refreshPorts();
    void connectToDevice();
    void resizecomboBox();
    void fetchOSInfo();
    void readData();



private:
    //QNetworkAccessManager *manager;
    QSerialPort *serialPort = nullptr;
    void logMessageToGuiAndFile(const QString &msg);
    bool firstTimeDeviceInfoShown = true;
    Ui::MainWindow *ui;
    QFile logFile; //logları yazmak için dosya nesnesi
    QTextStream logStream;

};

#endif // MAINWINDOW_H
