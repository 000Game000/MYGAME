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
signals:
    void clicked();
protected:
    virtual void mouseReleaseEvent(QMouseEvent *);
private:
    Ui::ColorSelection *ui;
    QColor color;
};

#endif // COLORSELECTION_H
