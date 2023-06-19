#ifndef BEGINWINDOW_H
#define BEGINWINDOW_H

#include <QWidget>

namespace Ui {
class BeginWindow;
}
/*
 * 开始游戏界面
 */
class BeginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BeginWindow(QWidget *parent = nullptr);
    ~BeginWindow();

private slots:
    void on_exitBtn_clicked();

    void on_StartBtn_clicked();

private:
    Ui::BeginWindow *ui;
};

#endif // BEGINWINDOW_H
