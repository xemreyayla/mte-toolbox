#ifndef UTILITIES_H
#define UTILITIES_H

#include <QWidget>

namespace Ui {
class utilities;
}

class utilities : public QWidget
{
    Q_OBJECT

public:
    explicit utilities(QWidget *parent = nullptr);
    ~utilities();

private:
    Ui::utilities *ui;
};

#endif // UTILITIES_H
