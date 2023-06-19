#include "BloodStrip.h"
#include "ui_BloodStrip.h"

BloodStrip::BloodStrip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BloodStrip)
{
    ui->setupUi(this);
}

BloodStrip::~BloodStrip()
{
    delete ui;
}
