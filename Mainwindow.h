
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include"Modules/Player.h"


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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void initWindows();                                                             //窗口关系初始化
    void initNewGame();                                                             //新游戏初始化
    QDateTime*time;                                                                 //游戏时间
    std::vector<MYGAME::People*> peopleList;                                        //角色表列
    void refresh();                                                                 //刷新
};
#endif // MAINWINDOW_H
