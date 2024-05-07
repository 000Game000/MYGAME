
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QGridLayout>
#include <Modules/System_.h>
#include"Person/Player.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*
 * 主界面
 */
typedef unsigned char UC;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:
    void NewGame(MYGAME::Player*player);

    void loadGame(QString sdir);

    void read(QString sdir);
private slots:

    void on_systemCommand_visibilityChanged(bool visible);

    void on_actionSave_S_triggered();

    void on_actionread_S_triggered();

private:
    const int buttonWidth=130;                                                              //按钮最小宽度
    const int buttonHeight=36;                                                              //按钮最小高度
    QDateTime*time;                                                                         //游戏时间
    Ui::MainWindow *ui;                                                                     //主窗口ui
    MYGAME::Player*player;                                                                  //主角指针
    MYGAME::System_*_system;                                                                //主角身上携带的系统
    std::vector<MYGAME::Map*> mapList;                                                      //游戏地图
    std::vector<QString*(MainWindow::*)(UC)> SystemCommandList;                             //按钮表列
    std::vector<MYGAME::People*> peopleList;                                                //角色表列

    void refresh();                                                                         //刷新
    void initMap();                                                                         //初始化游戏地图
    void recovery();                                                                        //恢复游戏(新游戏和读取存档)
    void initPeople();                                                                      //初始化主角以外的游戏角色
    void initWindows();                                                                     //窗口关系初始化
    void initSystemCommand();                                                               //初始化系统指令
    void initSystemCommandDockWidget();                                                     //初始化系统指令窗口
    template<class T>
    void gridLayoutWidget(QWidget*widget,T*type,std::vector<QString*(T::*)(UC)>*list);      //对widget进行栅格布局

    QString VersionNumber="0.0.1";                                                          //版本号
    QString*playerStatusFunction(UC flag=0);                                                //显示玩家状态
    QString*itemList(UC flag=0);                                                            //显示玩家所持物品表列
    QString*systemStore(UC flag=0);                                                         //显示系统商城
    QString*showPeopleList(UC flag=0);                                                      //显示人物表列
    QString*move(UC flag=0);                                                                //人物移动函数
    QString*moveStorey(UC flag=0);                                                          //上下楼函数
    QString*goOut(UC flag=0);                                                               //出门函数
    QString*enter(UC flag=0);                                                               //进入函数
    QString*addTime(UC flag=0);                                                             //添加时间

    //显示人物表列
    void showPeopleList();
    bool ifShowPeopleList();
};
#endif // MAINWINDOW_H
