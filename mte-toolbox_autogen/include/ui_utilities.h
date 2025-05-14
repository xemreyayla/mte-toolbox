/********************************************************************************
** Form generated from reading UI file 'utilities.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTILITIES_H
#define UI_UTILITIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_utilities
{
public:

    void setupUi(QWidget *utilities)
    {
        if (utilities->objectName().isEmpty())
            utilities->setObjectName("utilities");
        utilities->resize(400, 300);

        retranslateUi(utilities);

        QMetaObject::connectSlotsByName(utilities);
    } // setupUi

    void retranslateUi(QWidget *utilities)
    {
        utilities->setWindowTitle(QCoreApplication::translate("utilities", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class utilities: public Ui_utilities {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTILITIES_H
