#ifndef SIMPLEPEOPLEITEM_H
#define SIMPLEPEOPLEITEM_H

#include <QWidget>
#include "Person/Girl.h"
namespace Ui {
class SimplePeopleItem;
}

class SimplePeopleItem : public QWidget
{
    Q_OBJECT

public:
    explicit SimplePeopleItem(const MYGAME::Girl*girl,const QDateTime*time,QWidget *parent=nullptr);
    ~SimplePeopleItem();

private:
    Ui::SimplePeopleItem *ui;
};

#endif // SIMPLEPEOPLEITEM_H
