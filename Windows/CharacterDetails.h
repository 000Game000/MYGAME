#ifndef CHARACTERDETAILS_H
#define CHARACTERDETAILS_H

#include <QWidget>
#include <Map/Node.h>
#include "Person/Girl.h"
namespace Ui {
class CharacterDetails;
}

class CharacterDetails : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterDetails(QWidget *parent = nullptr);
    CharacterDetails(MYGAME::Girl *girl,std::unordered_map<QString,MYGAME::Node*>*mapList,QWidget *parent = nullptr);
    ~CharacterDetails();

private:
    void init();
    Ui::CharacterDetails *ui;
    MYGAME::Girl*girl;
    std::unordered_map<QString,MYGAME::Node*>*mapList;
};

#endif // CHARACTERDETAILS_H
