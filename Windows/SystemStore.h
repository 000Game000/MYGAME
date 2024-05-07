#ifndef SYSTEMSTORE_H
#define SYSTEMSTORE_H

#include <QWidget>
#include "Person/Player.h"
#include<QListWidgetItem>
#include <Modules/System_.h>
namespace Ui {
class SystemStore;
}
/*
 * 系统商店
 */
class SystemStore : public QWidget
{
    Q_OBJECT
    MYGAME::Player*player;                                                          //玩家类
    std::vector<MYGAME::ItemBase*>*itemList;                                        //系统贩卖的物品表列
    QListWidgetItem*selectItem;                                                     //保存选中的item
    MYGAME::ItemBase*item;                                                          //当前选中的物品
    bool flag=false;                                                                //当前物品是否在背包中拥有
public:
    explicit SystemStore(QWidget *parent = nullptr);
    SystemStore(MYGAME::Player*p,MYGAME::System_*_system,QWidget*parent=nullptr);
    ~SystemStore();

private slots:
    void on_stoneList_itemClicked(QListWidgetItem *item);

    void on_count_valueChanged(int);

    void on_buy_clicked();

private:
    Ui::SystemStore *ui;
};

#endif // SYSTEMSTORE_H
