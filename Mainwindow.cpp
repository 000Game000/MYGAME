#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "Modules/Modules.h"
#include "Windows/BeginWindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MYGAME::setMenu(this);
    BeginWindow*b=new BeginWindow();
    b->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
