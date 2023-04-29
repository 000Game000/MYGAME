#ifndef MODULES_H
#define MODULES_H
#include<QWidget>
namespace MYGAME {
//设置菜单
void setMenu(QWidget*widget);
//吉尔大小枚举类型
enum Size{
    Lovely=0,                                       //可爱的
    Sadness=1,                                      //短小的
    Boring=2,                                       //普通的
    Amazing=3,                                      //巨根
    Horse=4,                                        //规格外
    Beast=5,                                        //非人类
    Monster=6                                       //怪兽 龙鞭?
};
}
#endif // MODULES_H
