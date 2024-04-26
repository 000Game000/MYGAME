#ifndef LOAD_H
#define LOAD_H

#include <QFileInfoList>
#include <QListWidget>
#include <QWidget>

namespace Ui {
class Load;
}

class Load : public QWidget
{
    Q_OBJECT

public:
    explicit Load(QWidget *parent = nullptr);
    ~Load();
    void getDirs();
private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
signals:
    void sdir(QString sdir);
private:
    QFileInfoList fileList;
    Ui::Load *ui;
};

#endif // LOAD_H
