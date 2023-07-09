#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QWidget>
#include <QListWidgetItem>
#include "Person/Player.h"
namespace Ui {
class ItemList;
}
/*
 * 物品栏
 */
class ItemList : public QWidget
{
    Q_OBJECT
    MYGAME::Player*player;                                                          //人物类
    std::vector<MYGAME::ItemBase*>*itemList;                                        //物品表列
public:
    explicit ItemList(QWidget *parent = nullptr);
    ItemList(MYGAME::Player*player,QWidget *parent = nullptr);
    ~ItemList();
private slots:
    void on_itemList_itemClicked(QListWidgetItem *item);

private:
    Ui::ItemList *ui;
};

#endif // ITEMLIST_H
