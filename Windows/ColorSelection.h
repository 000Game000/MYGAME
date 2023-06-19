#ifndef COLORSELECTION_H
#define COLORSELECTION_H

#include <QWidget>
#include <QColorDialog>
namespace Ui {
class ColorSelection;
}

class ColorSelection : public QWidget
{
    Q_OBJECT

public:
    explicit ColorSelection(QWidget *parent = nullptr);
    ~ColorSelection();

    QColor getColor() const;
    void setColor(const QColor &newColor);
    void setColor(int R,int G,int B,int A=255);
signals:
    void clicked();
protected:
    virtual void mouseReleaseEvent(QMouseEvent *);
    //void paintEvent(QPaintEvent *event);
private:
    Ui::ColorSelection *ui;
    QColor color;
};

#endif // COLORSELECTION_H
