#ifndef STRIP_H
#define STRIP_H

#include <QWidget>

namespace Ui {
class Strip;
}

class Strip : public QWidget
{
    Q_OBJECT

public:
    explicit Strip(QWidget *parent = nullptr);
    ~Strip();

    long long getMaxValue() const;
    void setMaxValue(long long newMaxValue);

    long long getNowValue() const;
    void setNowValue(long long newNowValue);

    void paintEvent(QPaintEvent *);

    long long getFrame() const;
    void setFrame(long long newFrame);

    QString getBackground() const;
    void setBackground(const QString &newBackground);

    QString getProspect() const;
    void setProspect(const QString &newProspect);

private:
    Ui::Strip *ui;
    long long maxValue;                                     //进度条的最大值
    long long nowValue;                                     //当前值
    long long frame;                                        //边框大小
    QString background;                                     //背景图片
    QString prospect;                                       //前景图片
};

#endif // STRIP_H
