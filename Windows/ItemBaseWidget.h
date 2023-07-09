#ifndef ITEMBASEWIDGET_H
#define ITEMBASEWIDGET_H

#include <QWidget>
#include "Modules/Item/ItemBase.h"
namespace Ui {
class ItemBaseWidget;
}
/*
 * 基础物品列表项
 */
class ItemBaseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemBaseWidget(QWidget *parent = nullptr);
    ItemBaseWidget(MYGAME::ItemBase*item,QWidget *parent = nullptr);
    ~ItemBaseWidget();

    MYGAME::ItemBase *getItem() const;
    void setItem(MYGAME::ItemBase *newItem);

private:
    MYGAME::ItemBase*item;
    Ui::ItemBaseWidget *ui;
};

#endif // ITEMBASEWIDGET_H
