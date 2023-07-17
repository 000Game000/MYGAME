
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include"Person/Player.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*
 * 主界面
 */
class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
public slots:
    void NewGame(MYGAME::Player*player);
private slots:

    void on_systemStore_clicked();

    void on_itemList_clicked();

    void on_peopleList_clicked();

    void on_playerStatus_clicked();

private:
    Ui::MainWindow *ui;
    void initWindows();                                                             //窗口关系初始化
    void initNewGame();                                                             //新游戏初始化
    void initMap();                                                                 //初始化游戏地图
    std::vector<MYGAME::Map*> mapList;                                              //游戏地图
    QDateTime*time;                                                                 //游戏时间
    MYGAME::Player*player;                                                          //主角指针
    std::vector<MYGAME::People*> peopleList;                                        //角色表列
    void refresh();                                                                 //刷新
};
#endif // MAINWINDOW_H
