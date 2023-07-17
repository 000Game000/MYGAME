#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include <QWidget>
#include "Person/Player.h"
namespace Ui {
class PlayerStatus;
}

class PlayerStatus : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerStatus(QWidget *parent = nullptr);
    PlayerStatus(MYGAME::Player*player,QWidget *parent = nullptr);
    ~PlayerStatus();
private:
    MYGAME::Player*player;
    Ui::PlayerStatus *ui;
    void init();
};

#endif // PLAYERSTATUS_H
