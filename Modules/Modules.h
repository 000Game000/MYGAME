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
//身高枚举类型
enum Height{
    young=0,                                        //幼小
    Petite=1,                                       //娇小
    ordinary=2,                                     //普通
    tall=3,                                         //高大
    huge=4,                                         //巨大
};
//胖瘦枚举类型
enum Weight{
    emaciation=0,                                   //瘦削
    slender=1,                                      //纤细
    common=2,                                       //普通
    plump=3,                                        //丰满
    obesity=4                                       //肥胖
};
}
#endif // MODULES_H
