#include "BeginWindow.h"
#include "ui_BeginWindow.h"
#include "CreateLead.h"
#include "Load.h"
#include "Modules/Global.h"
BeginWindow::BeginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BeginWindow)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
}

BeginWindow::~BeginWindow()
{
    MYGAME::global.setBeginWindow(nullptr);
    delete ui;
}

void BeginWindow::sdirSlots(QString sdir)
{
    emit this->sdirSignals(sdir);
    this->close();
}

void BeginWindow::on_exitBtn_clicked()
{
    this->close();
}


void BeginWindow::on_StartBtn_clicked()
{
    if(MYGAME::global.getCreateLead()!=nullptr){
        MYGAME::global.getCreateLead()->show();
    }
    else{
        qDebug()<<"空指针";
    }
    this->close();
}

void BeginWindow::on_continueBtn_clicked()
{
    Load*P=new Load();
    connect(P,&Load::sdir,this,&BeginWindow::sdirSlots);
    P->show();
}

