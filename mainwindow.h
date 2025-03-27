#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QList>
#include <QtLogging>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QFile>
#include <QDateTime>
#include <QTextStream>




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


private:
    void logMessageToGuiAndFile(const QString &msg);

    Ui::MainWindow *ui;
    QFile logFile; //logları yazmak için dosya nesnesi
    QTextStream logStream;
    QSerialPort *serialPort;
};

#endif // MAINWINDOW_H
