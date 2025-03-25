#include "deviceinfo.h"
#include "ui_deviceinfo.h"

deviceinfo::deviceinfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deviceinfo)
{
    ui->setupUi(this);
}

deviceinfo::~deviceinfo()
{
    delete ui;
}
