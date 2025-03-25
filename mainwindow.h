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
#include <QDebug>
#include <QAbstractItemView>
#include <QMessageBox>


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
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
};

#endif // MAINWINDOW_H
