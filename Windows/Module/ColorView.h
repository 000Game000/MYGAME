#ifndef COLORVIEW_H
#define COLORVIEW_H

#include <QWidget>

namespace Ui {
class ColorView;
}

class ColorView : public QWidget
{
    Q_OBJECT

public:
    explicit ColorView(QWidget *parent = nullptr);
    ~ColorView();


    QColor getColor() const;
    void setColor(const QColor &newColor);

private:
    Ui::ColorView *ui;
    QColor color;
};

#endif // COLORVIEW_H
