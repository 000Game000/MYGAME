#ifndef CREATELEAD_H
#define CREATELEAD_H

#include <QWidget>
#include <QSpinBox>
#include <Modules/Player.h>
#include "Modules/Position/Penis.h"
namespace Ui {
class CreateLead;
}
/*
 * 创建主角页面
 */
class CreateLead : public QWidget
{
    Q_OBJECT

public:
    explicit CreateLead(QWidget *parent = nullptr);
    ~CreateLead();
signals:
    void NewGame(MYGAME::Player*player);
private slots:
    void on_WillpowerInput_valueChanged(int arg1);

    void on_QuickInput_valueChanged(int arg1);

    void on_PhysiqueInput_valueChanged(int arg1);

    void on_CharmInput_valueChanged(int arg1);

    void on_IntelligenceInput_valueChanged(int arg1);

    void on_heightHorizontalSlider_valueChanged(int value);

    void on_weightHorizontalSlider_valueChanged(int value);

    void on_dickSizeHorizontalSlider_valueChanged(int value);

    void on_EyeColorsEqual_stateChanged(int arg1);

    void on_complete_clicked();

private:
    Ui::CreateLead *ui;
    void initUI();                                                      //初始化UI
    void initPlayer();                                                  //初始化玩家对象
    MYGAME::Player*player;
    long long point;                                                    //角色点数
    void attributeChanged(QSpinBox*input);                              //基础属性修改函数
    QMap<QSpinBox*,MYGAME::Attribute*> maps;                            //建立QSpinbox和人物属性的联系
    MYGAME::Penis*penis;
};

#endif // CREATELEAD_H
