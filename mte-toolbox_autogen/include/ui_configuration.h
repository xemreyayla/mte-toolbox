/********************************************************************************
** Form generated from reading UI file 'configuration.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATION_H
#define UI_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configuration
{
public:

    void setupUi(QWidget *configuration)
    {
        if (configuration->objectName().isEmpty())
            configuration->setObjectName("configuration");
        configuration->resize(689, 350);

        retranslateUi(configuration);

        QMetaObject::connectSlotsByName(configuration);
    } // setupUi

    void retranslateUi(QWidget *configuration)
    {
        configuration->setWindowTitle(QCoreApplication::translate("configuration", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configuration: public Ui_configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
