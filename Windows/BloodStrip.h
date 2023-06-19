#ifndef BLOODSTRIP_H
#define BLOODSTRIP_H

#include <QWidget>

namespace Ui {
class BloodStrip;
}

class BloodStrip : public QWidget
{
    Q_OBJECT

public:
    explicit BloodStrip(QWidget *parent = nullptr);
    ~BloodStrip();

private:
    Ui::BloodStrip *ui;
};

#endif // BLOODSTRIP_H
