#include "configuration.h"
#include "ui_configuration.h"

configuration::configuration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::configuration)
{
    ui->setupUi(this);
}

configuration::~configuration()
{
    delete ui;
}
