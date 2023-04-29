#include "Modules.h"
#include<QMenuBar>
#include<QMenu>
#include"Windows/BeginWindow.h"
namespace MYGAME{
void setMenu(QWidget*widget){
    QMenuBar*menu=new QMenuBar(widget);
    QMenu*menu1=new QMenu("游戏(&G)",menu);
    QAction*gameAction1=new QAction("读取(&R)");
    QAction*gameAction2=new QAction("保存(&S)");
    QAction*gameAction3=new QAction("返回主菜单(&M)");
    menu1->addAction(gameAction1);
    menu1->addAction(gameAction2);
    menu1->addAction(gameAction3);
    menu->addMenu(menu1);
    widget->connect(gameAction3,&QAction::triggered,widget,[=]{
        BeginWindow *b=new BeginWindow();
        b->show();
        widget->close();
    });
}
}
