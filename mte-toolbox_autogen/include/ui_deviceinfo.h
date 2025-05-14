/********************************************************************************
** Form generated from reading UI file 'deviceinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEINFO_H
#define UI_DEVICEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deviceinfo
{
public:

    void setupUi(QWidget *deviceinfo)
    {
        if (deviceinfo->objectName().isEmpty())
            deviceinfo->setObjectName("deviceinfo");
        deviceinfo->resize(753, 526);

        retranslateUi(deviceinfo);

        QMetaObject::connectSlotsByName(deviceinfo);
    } // setupUi

    void retranslateUi(QWidget *deviceinfo)
    {
        deviceinfo->setWindowTitle(QCoreApplication::translate("deviceinfo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deviceinfo: public Ui_deviceinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEINFO_H
