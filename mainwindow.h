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
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QRegularExpression>
#include <QProcess>
#include <QThread>
#include <QTimer>
#include <QDir>
#include <QProgressDialog>


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
    void showConsolePage();
    void refreshPorts();
    void connectToDevice();
    void resizecomboBox();
    void fetchOSInfo();
    void readData();
    void fetchIpData();
    void rwConsole();
    void sdFormatButton_clicked();
    void rotateLogFileIfNeeded();
    void setIpLabelsError();
    void utilitiesButtons();
    void onSerialDataAvailable();
    void checkGpioStates();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort = nullptr;
    bool firstTimeDeviceInfoShown = true;
    bool sdCardFormattedRecently = false;
    QFile logFile;
    QTextStream logStream;
    QString removeAnsi(const QString &input);
    QString cleanTerminalOutput(const QString &input);
    QString readUntilJsonComplete(int overallTimeoutMs);
    void logMessageToGuiAndFile(const QString &msg);
    QTimer* gpioTimer;

};

#endif // MAINWINDOW_H
