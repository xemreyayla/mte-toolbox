#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QWidget>

namespace Ui {
class configuration;
}

class configuration : public QWidget
{
    Q_OBJECT

public:
    explicit configuration(QWidget *parent = nullptr);
    ~configuration();

private:
    Ui::configuration *ui;
};

#endif // CONFIGURATION_H
