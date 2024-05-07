#ifndef MAPLISTITEM_H
#define MAPLISTITEM_H

#include <QWidget>

namespace Ui {
class MapListItem;
}

class MapListItem : public QWidget
{
    Q_OBJECT

public:
    explicit MapListItem(QString name,QWidget *parent = nullptr);
    ~MapListItem();

private:
    Ui::MapListItem *ui;
};

#endif // MAPLISTITEM_H
