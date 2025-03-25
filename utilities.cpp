#include "utilities.h"
#include "ui_utilities.h"

utilities::utilities(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::utilities)
{
    ui->setupUi(this);
}

utilities::~utilities()
{
    delete ui;
}
