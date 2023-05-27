#include "BeginWindow.h"
#include "ui_BeginWindow.h"
#include "CreateLead.h"
BeginWindow::BeginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BeginWindow)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
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
    CreateLead*lead=new CreateLead;
    lead->show();
    this->close();
}
