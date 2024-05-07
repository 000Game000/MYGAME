#ifndef LOADITEM_H
#define LOADITEM_H

#include <QWidget>

namespace Ui {
class LoadItem;
}

class LoadItem : public QWidget
{
    Q_OBJECT

public:
    explicit LoadItem(QString dir,QWidget *parent = nullptr);
    ~LoadItem();
    QString dir;
private:
    Ui::LoadItem *ui;
};

#endif // LOADITEM_H
