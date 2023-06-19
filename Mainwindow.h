
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
private:
    Ui::MainWindow *ui;
    void initWindows();
    void initNewGame();
    QDateTime*time;
    std::vector<MYGAME::People*> peopleList;
};

#endif // MAINWINDOW_H
