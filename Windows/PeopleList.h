#ifndef PEOPLELIST_H
#define PEOPLELIST_H

#include <QWidget>
#include <Map/Node.h>
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
    PeopleList(std::vector<MYGAME::People *> *peopleList,const QDateTime* time,std::unordered_map<QString,MYGAME::Node*>*mapList,QWidget *parent = nullptr);
    ~PeopleList();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::PeopleList *ui;
    std::vector<MYGAME::People*>*peopleList;
    std::unordered_map<QString,MYGAME::Node*>*mapList;
};

#endif // PEOPLELIST_H
