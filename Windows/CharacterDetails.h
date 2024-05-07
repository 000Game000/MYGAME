#ifndef CHARACTERDETAILS_H
#define CHARACTERDETAILS_H

#include <QWidget>
#include "Person/Girl.h"
namespace Ui {
class CharacterDetails;
}

class CharacterDetails : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterDetails(QWidget *parent = nullptr);
    CharacterDetails(MYGAME::Girl *girl,QWidget *parent = nullptr);
    ~CharacterDetails();

private:
    void init();
    Ui::CharacterDetails *ui;
    MYGAME::Girl*girl;
};

#endif // CHARACTERDETAILS_H
