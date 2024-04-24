#ifndef MYSTRIP_H
#define MYSTRIP_H

#include <QWidget>

namespace Ui {
class MYStrip;
}

class MYStrip : public QWidget
{
    Q_OBJECT

public:
    explicit MYStrip(QWidget *parent = nullptr);
    ~MYStrip();

    unsigned long long getMaxValue() const;
    void setMaxValue(unsigned long long newMaxValue);
    unsigned long long getNowValue() const;
    void setNowValue(unsigned long long newNowValue);
    unsigned long long getFrame() const;
    void setFrame(unsigned long long newFrame);
    QString getBackground() const;
    void setBackground(const QString &newBackground);
    QString getProspect() const;
    void setProspect(const QString &newProspect);
    void paintEvent(QPaintEvent *);
private:
    Ui::MYStrip *ui;
    unsigned long long maxValue;                                     //进度条的最大值
    unsigned long long nowValue;                                     //当前值
    unsigned long long frame;                                        //边框大小
    QString background;                                              //背景图片
    QString prospect;                                                //前景图片
};

#endif // MYSTRIP_H
