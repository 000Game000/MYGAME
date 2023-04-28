#include "BeginWindow.h"
#include "ui_BeginWindow.h"
#include "Modules/Modules.h"
BeginWindow::BeginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BeginWindow)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
    MYGAME::setMenu(this);
}

BeginWindow::~BeginWindow()
{
    delete ui;
}

void BeginWindow::on_exitBtn_clicked()
{
    this->close();
}


void BeginWindow::on_StartBtn_clicked()
{

}

