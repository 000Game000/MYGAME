#ifndef PEOPLELISTITEM_H
#define PEOPLELISTITEM_H

#include <QWidget>
#include <Map/Node.h>
#include "Person/Girl.h"

namespace Ui {
class PeopleListItem;
}

class PeopleListItem : public QWidget
{
    Q_OBJECT

public:
    PeopleListItem(MYGAME::Girl *girl,const QDateTime*const time,std::unordered_map<QString,MYGAME::Node*>*mapList,QWidget *parent = nullptr);
    explicit PeopleListItem(QWidget *parent = nullptr);
    ~PeopleListItem();
private:
    Ui::PeopleListItem *ui;
    MYGAME::Girl*girl;
};

#endif // PEOPLELISTITEM_H
