#ifndef MYSTRIPADD_H
#define MYSTRIPADD_H

#include <QWidget>


namespace Ui {
class MYStripAdd;
}

class MYStripAdd : public QWidget
{
    Q_OBJECT
    QString name;
    QString unit;
    unsigned long long MAXValue;
    unsigned long long NOWValue;
public:
    explicit MYStripAdd(QWidget *parent = nullptr);
    ~MYStripAdd();

    QString getName() const;
    void setName(const QString &newName);

    QString getUnit() const;
    void setUnit(const QString &newUnit);

    void refresh();
    unsigned long long getMAXValue() const;
    void setMAXValue(unsigned long long newMAXValue);

    unsigned long long getNOWValue() const;
    void setNOWValue(unsigned long long newNOWValue);

    QString getBackground() const;
    void setBackground(QString newBackground);

    QString getProspect() const;
    void setProspect(QString newProspect);

    unsigned long long getFrame()const;
    void setFrame(unsigned long long newFrame);
private:
    Ui::MYStripAdd *ui;
};

#endif // MYSTRIPADD_H
