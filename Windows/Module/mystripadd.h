#ifndef MYSTRIPADD_H
#define MYSTRIPADD_H

#include <QWidget>

namespace Ui {
class MYStripAdd;
}

class MYStripAdd : public QWidget
{
    Q_OBJECT

public:
    explicit MYStripAdd(QWidget *parent = nullptr);
    ~MYStripAdd();

private:
    Ui::MYStripAdd *ui;
};

#endif // MYSTRIPADD_H
