/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *utilitiesButton;
    QPushButton *deviceinfoButton;
    QPushButton *connectionButton;
    QPushButton *consoleButton;
    QStackedWidget *stackedWidget;
    QWidget *DeviceInfoPage;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *osLabel;
    QLabel *kernelnOLabel;
    QLabel *nodenOLabel;
    QLabel *kernelrOLabel;
    QLabel *kernelvOLabel;
    QLabel *machinehOLabel;
    QLabel *hardwarepOlabel;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *kernelNameLabel;
    QLabel *nodeNameLabel;
    QLabel *kernelReleaseLabel;
    QLabel *kernelVersionLabel;
    QLabel *machineHardwareLabel;
    QLabel *hardwarePlatformLabel;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_7;
    QLabel *prettyNameLabel;
    QLabel *versionLabel;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QPlainTextEdit *buildInfoPlainTextEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *utestSerialLabel;
    QLabel *utestProductLabel;
    QLabel *appVersionLabel;
    QLabel *chipseeSerialLabel;
    QLabel *chipseeProductLabel;
    QLabel *lastModifiedLabel;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QWidget *UtilitiesPage;
    QGridLayout *gridLayout_21;
    QGridLayout *gridLayout_33;
    QGridLayout *gridLayout_32;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QLabel *connectionLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QLabel *formatLabel;
    QPushButton *getFirstStatusButton;
    QPushButton *sdFormatButton;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_13;
    QLabel *textLabel;
    QLabel *in1Label;
    QGridLayout *gridLayout_17;
    QLabel *label_18;
    QLabel *out1Label;
    QPushButton *out1LowButton;
    QPushButton *out1HighButton;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_22;
    QGridLayout *gridLayout_14;
    QLabel *textLabel_2;
    QLabel *in2Label;
    QGridLayout *gridLayout_18;
    QLabel *label_19;
    QLabel *out2Label;
    QPushButton *out2LowButton;
    QPushButton *out2HighButton;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_23;
    QGridLayout *gridLayout_15;
    QLabel *textLabel_3;
    QLabel *in3Label;
    QGridLayout *gridLayout_19;
    QLabel *out3Label;
    QLabel *label_20;
    QPushButton *out3LowButton;
    QPushButton *out3HighButton;
    QHBoxLayout *horizontalLayout_7;
    QGridLayout *gridLayout_24;
    QGridLayout *gridLayout_16;
    QLabel *textLabel_4;
    QLabel *in4Label;
    QGridLayout *gridLayout_20;
    QLabel *label_21;
    QLabel *out4Label;
    QPushButton *out4LowButton;
    QPushButton *out4HighButton;
    QWidget *ConsolePage;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_8;
    QPlainTextEdit *consolePlainTextEdit;
    QLineEdit *consoleLineEdit;
    QWidget *ConnectionPage;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QLabel *activeportsLabel;
    QComboBox *serialportscomboBox;
    QPlainTextEdit *plainTextEdit;
    QGridLayout *gridLayout_11;
    QPushButton *connectportsButton;
    QPushButton *refreshButton;
    QPushButton *disconnectButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(900, 600));
        MainWindow->setMaximumSize(QSize(1280, 800));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #2d2d2d;"));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName("gridLayout_4");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(1280, 80));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: #2d2d2d;\n"
"border: 1px solid #444;\n"
"border-radius: 8px;\n"
"color: #ffffff;\n"
""));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        utilitiesButton = new QPushButton(groupBox);
        utilitiesButton->setObjectName("utilitiesButton");
        sizePolicy.setHeightForWidth(utilitiesButton->sizePolicy().hasHeightForWidth());
        utilitiesButton->setSizePolicy(sizePolicy);
        utilitiesButton->setMinimumSize(QSize(180, 50));
        utilitiesButton->setAutoFillBackground(false);
        utilitiesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* Temel Stil */\n"
"    background-color: #f57c00;\n"
"    color: #212121;\n"
"	border: 1px solid rgba(80, 80, 80, 0.6);  /* #505050'nin opak versiyonu */\n"
"    \n"
"    /* Kenar Yumu\305\237atma */\n"
"    border-radius: 8px;  /* K\303\266\305\237eleri belirgin \305\237ekilde yuvarlak */\n"
"    \n"
"    /* Metin & Padding */\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 13pt;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff9800;  /* Daha a\303\247\304\261k turuncu */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e65100;  /* Daha koyu turuncu */\n"
"}"));

        gridLayout_2->addWidget(utilitiesButton, 0, 2, 1, 1);

        deviceinfoButton = new QPushButton(groupBox);
        deviceinfoButton->setObjectName("deviceinfoButton");
        sizePolicy.setHeightForWidth(deviceinfoButton->sizePolicy().hasHeightForWidth());
        deviceinfoButton->setSizePolicy(sizePolicy);
        deviceinfoButton->setMinimumSize(QSize(180, 50));
        deviceinfoButton->setAutoFillBackground(false);
        deviceinfoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* Temel Stil */\n"
"    background-color: #f57c00;\n"
"    color: #212121;\n"
"	border: 1px solid rgba(80, 80, 80, 0.6);  /* #505050'nin opak versiyonu */\n"
"    \n"
"    /* Kenar Yumu\305\237atma */\n"
"    border-radius: 8px;  /* K\303\266\305\237eleri belirgin \305\237ekilde yuvarlak */\n"
"    \n"
"    /* Metin & Padding */\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 13pt;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff9800;  /* Daha a\303\247\304\261k turuncu */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e65100;  /* Daha koyu turuncu */\n"
"}"));

        gridLayout_2->addWidget(deviceinfoButton, 0, 1, 1, 1);

        connectionButton = new QPushButton(groupBox);
        connectionButton->setObjectName("connectionButton");
        sizePolicy.setHeightForWidth(connectionButton->sizePolicy().hasHeightForWidth());
        connectionButton->setSizePolicy(sizePolicy);
        connectionButton->setMinimumSize(QSize(180, 50));
        connectionButton->setAutoFillBackground(false);
        connectionButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* Temel Stil */\n"
"    background-color: #f57c00;\n"
"    color: #212121;\n"
"	border: 1px solid rgba(80, 80, 80, 0.6);  /* #505050'nin opak versiyonu */\n"
"    \n"
"    /* Kenar Yumu\305\237atma */\n"
"    border-radius: 8px;  /* K\303\266\305\237eleri belirgin \305\237ekilde yuvarlak */\n"
"    \n"
"    /* Metin & Padding */\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 13pt;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff9800;  /* Daha a\303\247\304\261k turuncu */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e65100;  /* Daha koyu turuncu */\n"
"}"));

        gridLayout_2->addWidget(connectionButton, 0, 0, 1, 1);

        consoleButton = new QPushButton(groupBox);
        consoleButton->setObjectName("consoleButton");
        sizePolicy.setHeightForWidth(consoleButton->sizePolicy().hasHeightForWidth());
        consoleButton->setSizePolicy(sizePolicy);
        consoleButton->setMinimumSize(QSize(180, 50));
        consoleButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* Temel Stil */\n"
"    background-color: #f57c00;\n"
"    color: #212121;\n"
"	border: 1px solid rgba(80, 80, 80, 0.6);  /* #505050'nin opak versiyonu */\n"
"    \n"
"    /* Kenar Yumu\305\237atma */\n"
"    border-radius: 8px;  /* K\303\266\305\237eleri belirgin \305\237ekilde yuvarlak */\n"
"    \n"
"    /* Metin & Padding */\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 13pt;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff9800;  /* Daha a\303\247\304\261k turuncu */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e65100;  /* Daha koyu turuncu */\n"
"}"));

        gridLayout_2->addWidget(consoleButton, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy3);
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setMaximumSize(QSize(1280, 800));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #2d2d2d;"));
        stackedWidget->setFrameShape(QFrame::Shape::Box);
        stackedWidget->setFrameShadow(QFrame::Shadow::Plain);
        stackedWidget->setLineWidth(0);
        DeviceInfoPage = new QWidget();
        DeviceInfoPage->setObjectName("DeviceInfoPage");
        gridLayout_3 = new QGridLayout(DeviceInfoPage);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        osLabel = new QLabel(DeviceInfoPage);
        osLabel->setObjectName("osLabel");

        verticalLayout_6->addWidget(osLabel);

        kernelnOLabel = new QLabel(DeviceInfoPage);
        kernelnOLabel->setObjectName("kernelnOLabel");

        verticalLayout_6->addWidget(kernelnOLabel);

        nodenOLabel = new QLabel(DeviceInfoPage);
        nodenOLabel->setObjectName("nodenOLabel");

        verticalLayout_6->addWidget(nodenOLabel);

        kernelrOLabel = new QLabel(DeviceInfoPage);
        kernelrOLabel->setObjectName("kernelrOLabel");

        verticalLayout_6->addWidget(kernelrOLabel);

        kernelvOLabel = new QLabel(DeviceInfoPage);
        kernelvOLabel->setObjectName("kernelvOLabel");

        verticalLayout_6->addWidget(kernelvOLabel);

        machinehOLabel = new QLabel(DeviceInfoPage);
        machinehOLabel->setObjectName("machinehOLabel");

        verticalLayout_6->addWidget(machinehOLabel);

        hardwarepOlabel = new QLabel(DeviceInfoPage);
        hardwarepOlabel->setObjectName("hardwarepOlabel");
        hardwarepOlabel->setMinimumSize(QSize(90, 0));

        verticalLayout_6->addWidget(hardwarepOlabel);


        gridLayout->addLayout(verticalLayout_6, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(DeviceInfoPage);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(185, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout->addWidget(label_2);

        kernelNameLabel = new QLabel(DeviceInfoPage);
        kernelNameLabel->setObjectName("kernelNameLabel");
        kernelNameLabel->setMaximumSize(QSize(185, 16777215));

        verticalLayout->addWidget(kernelNameLabel);

        nodeNameLabel = new QLabel(DeviceInfoPage);
        nodeNameLabel->setObjectName("nodeNameLabel");
        nodeNameLabel->setMaximumSize(QSize(185, 16777215));

        verticalLayout->addWidget(nodeNameLabel);

        kernelReleaseLabel = new QLabel(DeviceInfoPage);
        kernelReleaseLabel->setObjectName("kernelReleaseLabel");
        kernelReleaseLabel->setMaximumSize(QSize(185, 16777215));

        verticalLayout->addWidget(kernelReleaseLabel);

        kernelVersionLabel = new QLabel(DeviceInfoPage);
        kernelVersionLabel->setObjectName("kernelVersionLabel");
        kernelVersionLabel->setMaximumSize(QSize(185, 16777215));

        verticalLayout->addWidget(kernelVersionLabel);

        machineHardwareLabel = new QLabel(DeviceInfoPage);
        machineHardwareLabel->setObjectName("machineHardwareLabel");
        machineHardwareLabel->setMaximumSize(QSize(185, 16777215));

        verticalLayout->addWidget(machineHardwareLabel);

        hardwarePlatformLabel = new QLabel(DeviceInfoPage);
        hardwarePlatformLabel->setObjectName("hardwarePlatformLabel");
        hardwarePlatformLabel->setMaximumSize(QSize(185, 16777215));

        verticalLayout->addWidget(hardwarePlatformLabel);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 2, 0, 1, 2);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName("gridLayout_12");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_9 = new QLabel(DeviceInfoPage);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(115, 16777215));

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(DeviceInfoPage);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(135, 16777215));

        verticalLayout_2->addWidget(label_10);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        prettyNameLabel = new QLabel(DeviceInfoPage);
        prettyNameLabel->setObjectName("prettyNameLabel");

        verticalLayout_7->addWidget(prettyNameLabel);

        versionLabel = new QLabel(DeviceInfoPage);
        versionLabel->setObjectName("versionLabel");

        verticalLayout_7->addWidget(versionLabel);


        horizontalLayout_2->addLayout(verticalLayout_7);


        gridLayout_12->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::ExpandingFieldsGrow);
        formLayout_3->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        label_7 = new QLabel(DeviceInfoPage);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(115, 140));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_7);

        buildInfoPlainTextEdit = new QPlainTextEdit(DeviceInfoPage);
        buildInfoPlainTextEdit->setObjectName("buildInfoPlainTextEdit");
        buildInfoPlainTextEdit->setMinimumSize(QSize(300, 150));
        buildInfoPlainTextEdit->setMaximumSize(QSize(320, 150));
        buildInfoPlainTextEdit->setStyleSheet(QString::fromUtf8("color: white;"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, buildInfoPlainTextEdit);


        gridLayout_12->addLayout(formLayout_3, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_12, 0, 3, 3, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_5 = new QLabel(DeviceInfoPage);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(185, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_4->addWidget(label_5);

        label_3 = new QLabel(DeviceInfoPage);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(185, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_4->addWidget(label_3);

        label = new QLabel(DeviceInfoPage);
        label->setObjectName("label");
        label->setMaximumSize(QSize(185, 16777215));
        label->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_4->addWidget(label);

        label_6 = new QLabel(DeviceInfoPage);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(185, 16777215));
        label_6->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_4->addWidget(label_6);

        label_4 = new QLabel(DeviceInfoPage);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(185, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_4->addWidget(label_4);

        label_8 = new QLabel(DeviceInfoPage);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(185, 16777215));

        verticalLayout_4->addWidget(label_8);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        utestSerialLabel = new QLabel(DeviceInfoPage);
        utestSerialLabel->setObjectName("utestSerialLabel");

        verticalLayout_5->addWidget(utestSerialLabel);

        utestProductLabel = new QLabel(DeviceInfoPage);
        utestProductLabel->setObjectName("utestProductLabel");

        verticalLayout_5->addWidget(utestProductLabel);

        appVersionLabel = new QLabel(DeviceInfoPage);
        appVersionLabel->setObjectName("appVersionLabel");

        verticalLayout_5->addWidget(appVersionLabel);

        chipseeSerialLabel = new QLabel(DeviceInfoPage);
        chipseeSerialLabel->setObjectName("chipseeSerialLabel");

        verticalLayout_5->addWidget(chipseeSerialLabel);

        chipseeProductLabel = new QLabel(DeviceInfoPage);
        chipseeProductLabel->setObjectName("chipseeProductLabel");

        verticalLayout_5->addWidget(chipseeProductLabel);

        lastModifiedLabel = new QLabel(DeviceInfoPage);
        lastModifiedLabel->setObjectName("lastModifiedLabel");
        lastModifiedLabel->setMinimumSize(QSize(90, 0));

        verticalLayout_5->addWidget(lastModifiedLabel);


        gridLayout_3->addLayout(verticalLayout_5, 0, 1, 1, 1);

        line = new QFrame(DeviceInfoPage);
        line->setObjectName("line");
        line->setStyleSheet(QString::fromUtf8("background-color: gray;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_3->addWidget(line, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        stackedWidget->addWidget(DeviceInfoPage);
        UtilitiesPage = new QWidget();
        UtilitiesPage->setObjectName("UtilitiesPage");
        gridLayout_21 = new QGridLayout(UtilitiesPage);
        gridLayout_21->setObjectName("gridLayout_21");
        gridLayout_33 = new QGridLayout();
        gridLayout_33->setObjectName("gridLayout_33");
        gridLayout_32 = new QGridLayout();
        gridLayout_32->setObjectName("gridLayout_32");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_13 = new QLabel(UtilitiesPage);
        label_13->setObjectName("label_13");
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMaximumSize(QSize(100, 100));

        horizontalLayout_3->addWidget(label_13);

        connectionLabel = new QLabel(UtilitiesPage);
        connectionLabel->setObjectName("connectionLabel");
        connectionLabel->setMinimumSize(QSize(90, 0));
        connectionLabel->setMaximumSize(QSize(580, 16777215));

        horizontalLayout_3->addWidget(connectionLabel);


        gridLayout_32->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_12 = new QLabel(UtilitiesPage);
        label_12->setObjectName("label_12");
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMaximumSize(QSize(100, 100));

        horizontalLayout_4->addWidget(label_12);

        formatLabel = new QLabel(UtilitiesPage);
        formatLabel->setObjectName("formatLabel");
        formatLabel->setMinimumSize(QSize(90, 0));
        formatLabel->setMaximumSize(QSize(580, 16777215));

        horizontalLayout_4->addWidget(formatLabel);


        gridLayout_32->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_33->addLayout(gridLayout_32, 0, 0, 1, 1);

        getFirstStatusButton = new QPushButton(UtilitiesPage);
        getFirstStatusButton->setObjectName("getFirstStatusButton");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(getFirstStatusButton->sizePolicy().hasHeightForWidth());
        getFirstStatusButton->setSizePolicy(sizePolicy4);
        getFirstStatusButton->setMinimumSize(QSize(144, 50));
        getFirstStatusButton->setMaximumSize(QSize(210, 16777215));
        getFirstStatusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0288D1; \n"
"    border: 2px solid #0288D1;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #03A9F4;  \n"
"    border: 2px solid #0288D1;\n"
"    color: white;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #01579B;  \n"
"}\n"
""));

        gridLayout_33->addWidget(getFirstStatusButton, 0, 1, 1, 1);

        sdFormatButton = new QPushButton(UtilitiesPage);
        sdFormatButton->setObjectName("sdFormatButton");
        sizePolicy4.setHeightForWidth(sdFormatButton->sizePolicy().hasHeightForWidth());
        sdFormatButton->setSizePolicy(sizePolicy4);
        sdFormatButton->setMinimumSize(QSize(144, 50));
        sdFormatButton->setMaximumSize(QSize(210, 16777215));
        sdFormatButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #01579B; \n"
"    border: 2px solid #01579B;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0288D1; \n"
"    border: 2px solid #01579B;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #002E63; \n"
"}"));

        gridLayout_33->addWidget(sdFormatButton, 0, 2, 1, 1);


        gridLayout_21->addLayout(gridLayout_33, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName("gridLayout_13");
        textLabel = new QLabel(UtilitiesPage);
        textLabel->setObjectName("textLabel");
        sizePolicy.setHeightForWidth(textLabel->sizePolicy().hasHeightForWidth());
        textLabel->setSizePolicy(sizePolicy);
        textLabel->setMinimumSize(QSize(25, 20));
        textLabel->setMaximumSize(QSize(20, 20));

        gridLayout_13->addWidget(textLabel, 0, 0, 1, 1);

        in1Label = new QLabel(UtilitiesPage);
        in1Label->setObjectName("in1Label");
        in1Label->setMinimumSize(QSize(50, 0));

        gridLayout_13->addWidget(in1Label, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_13, 0, 0, 1, 1);

        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName("gridLayout_17");
        label_18 = new QLabel(UtilitiesPage);
        label_18->setObjectName("label_18");
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(40, 2));
        label_18->setMaximumSize(QSize(40, 20));

        gridLayout_17->addWidget(label_18, 0, 0, 1, 1);

        out1Label = new QLabel(UtilitiesPage);
        out1Label->setObjectName("out1Label");
        out1Label->setMinimumSize(QSize(50, 0));

        gridLayout_17->addWidget(out1Label, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_17, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_6);

        out1LowButton = new QPushButton(UtilitiesPage);
        out1LowButton->setObjectName("out1LowButton");
        out1LowButton->setMaximumSize(QSize(210, 16777215));
        out1LowButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F44336;  /* canl\304\261 k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #D32F2F;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E53935;  /* biraz daha koyu k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #B71C1C;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c;  /* \303\207ok koyu k\304\261rm\304\261z\304\261 */\n"
"}"));

        horizontalLayout->addWidget(out1LowButton);

        out1HighButton = new QPushButton(UtilitiesPage);
        out1HighButton->setObjectName("out1HighButton");
        out1HighButton->setMaximumSize(QSize(210, 16777215));
        out1HighButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;  /* canl\304\261 ye\305\237il */\n"
"    border: 2px solid #388E3C;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43A047;  /* hover: biraz koyu ye\305\237il */\n"
"    border: 2px solid #2E7D32;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2E7D32;  /* bas\304\261l\304\261yken: daha da koyu ye\305\237il */\n"
"    border: 2px solid #1B5E20;\n"
"    color: white;\n"
"}\n"
""));

        horizontalLayout->addWidget(out1HighButton);


        gridLayout_21->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        gridLayout_22 = new QGridLayout();
        gridLayout_22->setObjectName("gridLayout_22");
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName("gridLayout_14");
        textLabel_2 = new QLabel(UtilitiesPage);
        textLabel_2->setObjectName("textLabel_2");
        sizePolicy.setHeightForWidth(textLabel_2->sizePolicy().hasHeightForWidth());
        textLabel_2->setSizePolicy(sizePolicy);
        textLabel_2->setMinimumSize(QSize(25, 20));
        textLabel_2->setMaximumSize(QSize(20, 20));

        gridLayout_14->addWidget(textLabel_2, 0, 0, 1, 1);

        in2Label = new QLabel(UtilitiesPage);
        in2Label->setObjectName("in2Label");
        in2Label->setMinimumSize(QSize(50, 0));

        gridLayout_14->addWidget(in2Label, 0, 1, 1, 1);


        gridLayout_22->addLayout(gridLayout_14, 0, 0, 1, 1);

        gridLayout_18 = new QGridLayout();
        gridLayout_18->setObjectName("gridLayout_18");
        label_19 = new QLabel(UtilitiesPage);
        label_19->setObjectName("label_19");
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setMinimumSize(QSize(40, 2));
        label_19->setMaximumSize(QSize(40, 20));

        gridLayout_18->addWidget(label_19, 0, 0, 1, 1);

        out2Label = new QLabel(UtilitiesPage);
        out2Label->setObjectName("out2Label");
        out2Label->setMinimumSize(QSize(50, 0));

        gridLayout_18->addWidget(out2Label, 0, 1, 1, 1);


        gridLayout_22->addLayout(gridLayout_18, 0, 1, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_22);

        out2LowButton = new QPushButton(UtilitiesPage);
        out2LowButton->setObjectName("out2LowButton");
        out2LowButton->setMaximumSize(QSize(210, 16777215));
        out2LowButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F44336;  /* canl\304\261 k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #D32F2F;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E53935;  /* biraz daha koyu k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #B71C1C;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c;  /* \303\207ok koyu k\304\261rm\304\261z\304\261 */\n"
"}"));

        horizontalLayout_5->addWidget(out2LowButton);

        out2HighButton = new QPushButton(UtilitiesPage);
        out2HighButton->setObjectName("out2HighButton");
        out2HighButton->setMaximumSize(QSize(210, 16777215));
        out2HighButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;  /* canl\304\261 ye\305\237il */\n"
"    border: 2px solid #388E3C;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43A047;  /* hover: biraz koyu ye\305\237il */\n"
"    border: 2px solid #2E7D32;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2E7D32;  /* bas\304\261l\304\261yken: daha da koyu ye\305\237il */\n"
"    border: 2px solid #1B5E20;\n"
"    color: white;\n"
"}\n"
""));

        horizontalLayout_5->addWidget(out2HighButton);


        gridLayout_21->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        gridLayout_23 = new QGridLayout();
        gridLayout_23->setObjectName("gridLayout_23");
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName("gridLayout_15");
        textLabel_3 = new QLabel(UtilitiesPage);
        textLabel_3->setObjectName("textLabel_3");
        sizePolicy.setHeightForWidth(textLabel_3->sizePolicy().hasHeightForWidth());
        textLabel_3->setSizePolicy(sizePolicy);
        textLabel_3->setMinimumSize(QSize(25, 20));
        textLabel_3->setMaximumSize(QSize(20, 20));

        gridLayout_15->addWidget(textLabel_3, 0, 0, 1, 1);

        in3Label = new QLabel(UtilitiesPage);
        in3Label->setObjectName("in3Label");
        in3Label->setMinimumSize(QSize(50, 0));

        gridLayout_15->addWidget(in3Label, 0, 1, 1, 1);


        gridLayout_23->addLayout(gridLayout_15, 0, 0, 1, 1);

        gridLayout_19 = new QGridLayout();
        gridLayout_19->setObjectName("gridLayout_19");
        out3Label = new QLabel(UtilitiesPage);
        out3Label->setObjectName("out3Label");
        out3Label->setMinimumSize(QSize(50, 0));

        gridLayout_19->addWidget(out3Label, 0, 1, 1, 1);

        label_20 = new QLabel(UtilitiesPage);
        label_20->setObjectName("label_20");
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setMinimumSize(QSize(40, 2));
        label_20->setMaximumSize(QSize(40, 20));

        gridLayout_19->addWidget(label_20, 0, 0, 1, 1);


        gridLayout_23->addLayout(gridLayout_19, 0, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_23);

        out3LowButton = new QPushButton(UtilitiesPage);
        out3LowButton->setObjectName("out3LowButton");
        out3LowButton->setMaximumSize(QSize(210, 16777215));
        out3LowButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F44336;  /* canl\304\261 k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #D32F2F;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E53935;  /* biraz daha koyu k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #B71C1C;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c;  /* \303\207ok koyu k\304\261rm\304\261z\304\261 */\n"
"}"));

        horizontalLayout_6->addWidget(out3LowButton);

        out3HighButton = new QPushButton(UtilitiesPage);
        out3HighButton->setObjectName("out3HighButton");
        out3HighButton->setMaximumSize(QSize(210, 16777215));
        out3HighButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;  /* canl\304\261 ye\305\237il */\n"
"    border: 2px solid #388E3C;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43A047;  /* hover: biraz koyu ye\305\237il */\n"
"    border: 2px solid #2E7D32;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2E7D32;  /* bas\304\261l\304\261yken: daha da koyu ye\305\237il */\n"
"    border: 2px solid #1B5E20;\n"
"    color: white;\n"
"}\n"
""));

        horizontalLayout_6->addWidget(out3HighButton);


        gridLayout_21->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        gridLayout_24 = new QGridLayout();
        gridLayout_24->setObjectName("gridLayout_24");
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName("gridLayout_16");
        textLabel_4 = new QLabel(UtilitiesPage);
        textLabel_4->setObjectName("textLabel_4");
        sizePolicy.setHeightForWidth(textLabel_4->sizePolicy().hasHeightForWidth());
        textLabel_4->setSizePolicy(sizePolicy);
        textLabel_4->setMinimumSize(QSize(25, 20));
        textLabel_4->setMaximumSize(QSize(20, 20));

        gridLayout_16->addWidget(textLabel_4, 0, 0, 1, 1);

        in4Label = new QLabel(UtilitiesPage);
        in4Label->setObjectName("in4Label");
        in4Label->setMinimumSize(QSize(50, 0));

        gridLayout_16->addWidget(in4Label, 0, 1, 1, 1);


        gridLayout_24->addLayout(gridLayout_16, 0, 0, 1, 1);

        gridLayout_20 = new QGridLayout();
        gridLayout_20->setObjectName("gridLayout_20");
        label_21 = new QLabel(UtilitiesPage);
        label_21->setObjectName("label_21");
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setMinimumSize(QSize(40, 2));
        label_21->setMaximumSize(QSize(40, 20));

        gridLayout_20->addWidget(label_21, 0, 0, 1, 1);

        out4Label = new QLabel(UtilitiesPage);
        out4Label->setObjectName("out4Label");
        out4Label->setMinimumSize(QSize(50, 0));

        gridLayout_20->addWidget(out4Label, 0, 1, 1, 1);


        gridLayout_24->addLayout(gridLayout_20, 0, 1, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_24);

        out4LowButton = new QPushButton(UtilitiesPage);
        out4LowButton->setObjectName("out4LowButton");
        out4LowButton->setMaximumSize(QSize(210, 16777215));
        out4LowButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F44336;  /* canl\304\261 k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #D32F2F;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E53935;  /* biraz daha koyu k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #B71C1C;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c;  /* \303\207ok koyu k\304\261rm\304\261z\304\261 */\n"
"}"));

        horizontalLayout_7->addWidget(out4LowButton);

        out4HighButton = new QPushButton(UtilitiesPage);
        out4HighButton->setObjectName("out4HighButton");
        out4HighButton->setMaximumSize(QSize(210, 16777215));
        out4HighButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;  /* canl\304\261 ye\305\237il */\n"
"    border: 2px solid #388E3C;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43A047;  /* hover: biraz koyu ye\305\237il */\n"
"    border: 2px solid #2E7D32;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2E7D32;  /* bas\304\261l\304\261yken: daha da koyu ye\305\237il */\n"
"    border: 2px solid #1B5E20;\n"
"    color: white;\n"
"}\n"
""));

        horizontalLayout_7->addWidget(out4HighButton);


        gridLayout_21->addLayout(horizontalLayout_7, 4, 0, 1, 1);

        stackedWidget->addWidget(UtilitiesPage);
        ConsolePage = new QWidget();
        ConsolePage->setObjectName("ConsolePage");
        gridLayout_5 = new QGridLayout(ConsolePage);
        gridLayout_5->setObjectName("gridLayout_5");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        consolePlainTextEdit = new QPlainTextEdit(ConsolePage);
        consolePlainTextEdit->setObjectName("consolePlainTextEdit");
        consolePlainTextEdit->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: black;\n"
"font-family: DejaVu Sans Mono, Liberation Mono, Monospace;\n"
"font-size: 11pt;\n"
""));

        verticalLayout_8->addWidget(consolePlainTextEdit);

        consoleLineEdit = new QLineEdit(ConsolePage);
        consoleLineEdit->setObjectName("consoleLineEdit");
        consoleLineEdit->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: black;\n"
"font-family: DejaVu Sans Mono, Liberation Mono, Monospace;\n"
"font-size: 11pt;\n"
""));

        verticalLayout_8->addWidget(consoleLineEdit);


        gridLayout_5->addLayout(verticalLayout_8, 0, 0, 1, 1);

        stackedWidget->addWidget(ConsolePage);
        ConnectionPage = new QWidget();
        ConnectionPage->setObjectName("ConnectionPage");
        gridLayout_7 = new QGridLayout(ConnectionPage);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName("gridLayout_8");
        activeportsLabel = new QLabel(ConnectionPage);
        activeportsLabel->setObjectName("activeportsLabel");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(activeportsLabel->sizePolicy().hasHeightForWidth());
        activeportsLabel->setSizePolicy(sizePolicy5);
        activeportsLabel->setMaximumSize(QSize(80, 50));
        activeportsLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 10pt;"));

        gridLayout_8->addWidget(activeportsLabel, 0, 0, 1, 1);

        serialportscomboBox = new QComboBox(ConnectionPage);
        serialportscomboBox->setObjectName("serialportscomboBox");
        sizePolicy1.setHeightForWidth(serialportscomboBox->sizePolicy().hasHeightForWidth());
        serialportscomboBox->setSizePolicy(sizePolicy1);
        serialportscomboBox->setMinimumSize(QSize(350, 0));
        serialportscomboBox->setMaximumSize(QSize(620, 60));
        serialportscomboBox->setSizeIncrement(QSize(0, 0));
        serialportscomboBox->setBaseSize(QSize(0, 0));
        serialportscomboBox->setMouseTracking(false);
        serialportscomboBox->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 10pt;\n"
""));
        serialportscomboBox->setMaxVisibleItems(10);
        serialportscomboBox->setInsertPolicy(QComboBox::InsertPolicy::InsertAtBottom);
        serialportscomboBox->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        serialportscomboBox->setMinimumContentsLength(0);
        serialportscomboBox->setIconSize(QSize(16, 16));
        serialportscomboBox->setFrame(true);
        serialportscomboBox->setModelColumn(0);

        gridLayout_8->addWidget(serialportscomboBox, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(ConnectionPage);
        plainTextEdit->setObjectName("plainTextEdit");
        sizePolicy3.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy3);
        plainTextEdit->setMinimumSize(QSize(600, 150));
        plainTextEdit->setMaximumSize(QSize(750, 16777215));
        plainTextEdit->setSizeIncrement(QSize(1080, 720));
        plainTextEdit->setAutoFillBackground(false);
        plainTextEdit->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 10pt;\n"
""));
        plainTextEdit->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);

        gridLayout_9->addWidget(plainTextEdit, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        connectportsButton = new QPushButton(ConnectionPage);
        connectportsButton->setObjectName("connectportsButton");
        sizePolicy5.setHeightForWidth(connectportsButton->sizePolicy().hasHeightForWidth());
        connectportsButton->setSizePolicy(sizePolicy5);
        connectportsButton->setMinimumSize(QSize(100, 75));
        connectportsButton->setMaximumSize(QSize(175, 60));
        connectportsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        connectportsButton->setStyleSheet(QString::fromUtf8("#connectportsButton {\n"
"    background-color: #3BC406; /* normal ye\305\237il */\n"
"    color: white;\n"
"    border: 2px solid #388E3C;\n"
"    border-radius: 6px;\n"
"font-family: 'Segoe UI', sans-serif;\n"
"font-size: 12pt;\n"
"font-weight: bold;\n"
"\n"
"}\n"
"\n"
"#connectportsButton:hover {\n"
"    background-color: #43A047; /* biraz koyu ye\305\237il */\n"
"    border: 2px solid #2E7D32;\n"
"}\n"
"\n"
"\n"
""));

        gridLayout_11->addWidget(connectportsButton, 0, 0, 1, 1);

        refreshButton = new QPushButton(ConnectionPage);
        refreshButton->setObjectName("refreshButton");
        sizePolicy5.setHeightForWidth(refreshButton->sizePolicy().hasHeightForWidth());
        refreshButton->setSizePolicy(sizePolicy5);
        refreshButton->setMinimumSize(QSize(100, 75));
        refreshButton->setMaximumSize(QSize(175, 60));
        refreshButton->setStyleSheet(QString::fromUtf8("#refreshButton {\n"
"background-color: #FFA000;  /* kehribar sar\304\261s\304\261, turuncuya yak\304\261n */\n"
"    color: white;\n"
"    border: 2px solid #EA9403;\n"
"    border-radius: 6px;\n"
"font-family: 'Segoe UI', sans-serif;\n"
"font-size: 12pt;\n"
"font-weight: bold;\n"
"}\n"
"\n"
"#refreshButton:hover {\n"
"   background-color: #EAA503;  /* biraz koyusu */\n"
"    border: 2px solid #FF8F00;\n"
"}\n"
""));

        gridLayout_11->addWidget(refreshButton, 1, 0, 1, 1);

        disconnectButton = new QPushButton(ConnectionPage);
        disconnectButton->setObjectName("disconnectButton");
        sizePolicy5.setHeightForWidth(disconnectButton->sizePolicy().hasHeightForWidth());
        disconnectButton->setSizePolicy(sizePolicy5);
        disconnectButton->setMinimumSize(QSize(100, 75));
        disconnectButton->setMaximumSize(QSize(175, 60));
        disconnectButton->setStyleSheet(QString::fromUtf8("#disconnectButton {\n"
"    background-color: #F44336;  /* canl\304\261 k\304\261rm\304\261z\304\261 */\n"
"    color: white;\n"
"    border: 2px solid #C62828;\n"
"    border-radius: 6px;\n"
"font-family: 'Segoe UI', sans-serif;\n"
"font-size: 12pt;\n"
"font-weight: bold;\n"
"}\n"
"\n"
"#disconnectButton:hover {\n"
"    background-color: #E53935;  /* biraz daha koyu k\304\261rm\304\261z\304\261 */\n"
"    border: 2px solid #B71C1C;\n"
"}\n"
""));

        gridLayout_11->addWidget(disconnectButton, 2, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_11, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_10, 0, 0, 1, 1);

        stackedWidget->addWidget(ConnectionPage);

        gridLayout_4->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        connectportsButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "First Qt Project", nullptr));
        groupBox->setTitle(QString());
        utilitiesButton->setText(QCoreApplication::translate("MainWindow", "Utilities", nullptr));
        deviceinfoButton->setText(QCoreApplication::translate("MainWindow", "Device Info", nullptr));
        connectionButton->setText(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        consoleButton->setText(QCoreApplication::translate("MainWindow", "Console", nullptr));
#if QT_CONFIG(tooltip)
        stackedWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        osLabel->setText(QString());
        kernelnOLabel->setText(QString());
        nodenOLabel->setText(QString());
        kernelrOLabel->setText(QString());
        kernelvOLabel->setText(QString());
        machinehOLabel->setText(QString());
        hardwarepOlabel->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "OS:", nullptr));
        kernelNameLabel->setText(QCoreApplication::translate("MainWindow", "Kernel Name:", nullptr));
        nodeNameLabel->setText(QCoreApplication::translate("MainWindow", "Node Name:", nullptr));
        kernelReleaseLabel->setText(QCoreApplication::translate("MainWindow", "Kernel Release:", nullptr));
        kernelVersionLabel->setText(QCoreApplication::translate("MainWindow", "Kernel Version:", nullptr));
        machineHardwareLabel->setText(QCoreApplication::translate("MainWindow", "Machine Hardware Name:", nullptr));
        hardwarePlatformLabel->setText(QCoreApplication::translate("MainWindow", "Hardware Platform:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Pretty Name:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Version:", nullptr));
        prettyNameLabel->setText(QString());
        versionLabel->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Build Info:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Utest Serial Number:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Utest Product Number:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Application Version:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Chipsee Serial Number:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Chipsee Product Number:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Last Modified:", nullptr));
        utestSerialLabel->setText(QString());
        utestProductLabel->setText(QString());
        appVersionLabel->setText(QString());
        chipseeSerialLabel->setText(QString());
        chipseeProductLabel->setText(QString());
        lastModifiedLabel->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Connection Info:", nullptr));
        connectionLabel->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Formatting Info:", nullptr));
        formatLabel->setText(QString());
        getFirstStatusButton->setText(QCoreApplication::translate("MainWindow", "GET STATUS", nullptr));
        sdFormatButton->setText(QCoreApplication::translate("MainWindow", "SD CARD FORMAT", nullptr));
        textLabel->setText(QCoreApplication::translate("MainWindow", "IN1:", nullptr));
        in1Label->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "OUT1:", nullptr));
        out1Label->setText(QString());
        out1LowButton->setText(QCoreApplication::translate("MainWindow", "SET LOW", nullptr));
        out1HighButton->setText(QCoreApplication::translate("MainWindow", "SET HIGH", nullptr));
        textLabel_2->setText(QCoreApplication::translate("MainWindow", "IN2:", nullptr));
        in2Label->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "OUT2:", nullptr));
        out2Label->setText(QString());
        out2LowButton->setText(QCoreApplication::translate("MainWindow", "SET LOW", nullptr));
        out2HighButton->setText(QCoreApplication::translate("MainWindow", "SET HIGH", nullptr));
        textLabel_3->setText(QCoreApplication::translate("MainWindow", "IN3:", nullptr));
        in3Label->setText(QString());
        out3Label->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "OUT3:", nullptr));
        out3LowButton->setText(QCoreApplication::translate("MainWindow", "SET LOW", nullptr));
        out3HighButton->setText(QCoreApplication::translate("MainWindow", "SET HIGH", nullptr));
        textLabel_4->setText(QCoreApplication::translate("MainWindow", "IN4:", nullptr));
        in4Label->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "OUT4:", nullptr));
        out4Label->setText(QString());
        out4LowButton->setText(QCoreApplication::translate("MainWindow", "SET LOW", nullptr));
        out4HighButton->setText(QCoreApplication::translate("MainWindow", "SET HIGH", nullptr));
        activeportsLabel->setText(QCoreApplication::translate("MainWindow", "Active Ports:", nullptr));
        connectportsButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        disconnectButton->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
