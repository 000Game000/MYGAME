#ifndef MODULES_H
#define MODULES_H
#include<QWidget>
namespace MYGAME {
//设置菜单
void setMenu(QWidget*widget);
//吉尔大小枚举类型
enum DickSize{
    Lovely,                                         //可爱的
    Sadness,                                        //短小的
    Boring,                                         //普通的
    Amazing,                                        //巨根
    Horse,                                          //规格外
    Beast,                                          //非人类
    Monster,                                        //怪兽 龙鞭?
    sizeCount                                       //计数有多少个size项
};
//身高枚举类型
enum Height{
    young,                                          //幼小
    Petite,                                         //娇小
    ordinary,                                       //普通
    tall,                                           //高大
    huge,                                           //巨大
    heightCount                                     //计数有多少个身高标签
};
//胖瘦枚举类型
enum Weight{
    emaciation,                                     //瘦削
    slender,                                        //纤细
    common,                                         //普通
    plump,                                          //丰满
    obesity,                                        //肥胖
    weightCount                                     //计数有多少个胖瘦标签
};
void setMenu(QWidget*widget);                       //设置菜单
QString getValue(QString str);
}
#endif // MODULES_H
