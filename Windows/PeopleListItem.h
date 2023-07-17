#ifndef PEOPLELISTITEM_H
#define PEOPLELISTITEM_H

#include <QWidget>

namespace Ui {
class PeopleListItem;
}

class PeopleListItem : public QWidget
{
    Q_OBJECT

public:
    explicit PeopleListItem(QWidget *parent = nullptr);
    ~PeopleListItem();

private:
    Ui::PeopleListItem *ui;
};

#endif // PEOPLELISTITEM_H
