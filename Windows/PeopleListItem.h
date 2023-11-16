#ifndef PEOPLELISTITEM_H
#define PEOPLELISTITEM_H

#include <QWidget>
#include "Person/Girl.h"
namespace Ui {
class PeopleListItem;
}

class PeopleListItem : public QWidget
{
    Q_OBJECT

public:
    PeopleListItem(MYGAME::Girl *girl,QWidget *parent = nullptr);
    explicit PeopleListItem(QWidget *parent = nullptr);
    ~PeopleListItem();
private:
    Ui::PeopleListItem *ui;
    MYGAME::Girl*girl;
};

#endif // PEOPLELISTITEM_H
