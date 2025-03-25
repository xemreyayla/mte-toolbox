#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QWidget>

namespace Ui {
class deviceinfo;
}

class deviceinfo : public QWidget
{
    Q_OBJECT

public:
    explicit deviceinfo(QWidget *parent = nullptr);
    ~deviceinfo();

private:
    Ui::deviceinfo *ui;
};

#endif // DEVICEINFO_H
