#ifndef CREATELEAD_H
#define CREATELEAD_H

#include <QWidget>
#include <QSpinBox>
#include <Modules/Player.h>
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

private:
    Ui::CreateLead *ui;
    void init();
    MYGAME::Player player;
    struct QSpinBoxs{
        QSpinBox*Willpower;
        QSpinBox*Quick;
        QSpinBox*Physique;
        QSpinBox*Charm;
        QSpinBox*Intelligence;
    }boxs;
};

#endif // CREATELEAD_H
