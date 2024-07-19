#ifndef MAPLISTITEM_H
#define MAPLISTITEM_H

#include <QWidget>

#include <Map/Node.h>

namespace Ui {
class MapListItem;
}

class MapListItem : public QWidget
{
    Q_OBJECT

public:
    explicit MapListItem(QString name,long long money,long long time,QWidget *parent = nullptr);
    ~MapListItem();

private:
    Ui::MapListItem *ui;
};

#endif // MAPLISTITEM_H
