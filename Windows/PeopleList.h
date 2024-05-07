#ifndef PEOPLELIST_H
#define PEOPLELIST_H

#include <QWidget>
#include"Person/People.h"
#include "qlistwidget.h"
namespace Ui {
class PeopleList;
}

class PeopleList : public QWidget
{
    Q_OBJECT

public:
    explicit PeopleList(QWidget *parent = nullptr);
    PeopleList(std::vector<MYGAME::People *> *peopleList,const QDateTime* time,QWidget *parent = nullptr);
    ~PeopleList();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::PeopleList *ui;
    std::vector<MYGAME::People*>*peopleList;
};

#endif // PEOPLELIST_H
