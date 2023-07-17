#ifndef PEOPLELIST_H
#define PEOPLELIST_H

#include <QWidget>
#include"Person/Player.h"
namespace Ui {
class PeopleList;
}

class PeopleList : public QWidget
{
    Q_OBJECT

public:
    explicit PeopleList(QWidget *parent = nullptr);
    PeopleList(MYGAME::Player *player, std::vector<MYGAME::People *> *peopleList,QWidget *parent = nullptr);

    ~PeopleList();

private:
    Ui::PeopleList *ui;
    MYGAME::Player*player;
    std::vector<MYGAME::People*>*peopleList;
};

#endif // PEOPLELIST_H
