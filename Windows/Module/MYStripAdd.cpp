#include "MYStripAdd.h"
#include "ui_MYStripAdd.h"

QString MYStripAdd::getName() const
{
    return name;
}

void MYStripAdd::setName(const QString &newName)
{
    name = newName;
    this->refresh();
}

QString MYStripAdd::getUnit() const
{
    return unit;
}

void MYStripAdd::setUnit(const QString &newUnit)
{
    unit = newUnit;
    this->refresh();
}

void MYStripAdd::refresh()
{
    ui->name->setText(this->name+":");
    ui->number->setText(QString::number(this->NOWValue)+"/"+QString::number(this->MAXValue)+this->unit);
}

unsigned long long MYStripAdd::getMAXValue() const
{

    return MAXValue;
}

void MYStripAdd::setMAXValue(unsigned long long newMAXValue)
{
    MAXValue = newMAXValue;
    ui->Strip->setMaxValue(this->MAXValue);
    this->refresh();
}

unsigned long long MYStripAdd::getNOWValue() const
{
    return NOWValue;
}

void MYStripAdd::setNOWValue(unsigned long long newNOWValue)
{
    NOWValue = newNOWValue;
    ui->Strip->setNowValue(this->NOWValue);
    this->refresh();
}

QString MYStripAdd::getBackground() const
{
    return ui->Strip->getBackground();
}

void MYStripAdd::setBackground(QString newBackground)
{
    ui->Strip->setBackground(newBackground);
}

QString MYStripAdd::getProspect() const
{
    return ui->Strip->getProspect();
}

void MYStripAdd::setProspect(QString newProspect)
{
    ui->Strip->setProspect(newProspect);
}

unsigned long long MYStripAdd::getFrame() const
{
    return ui->Strip->getFrame();
}

void MYStripAdd::setFrame(unsigned long long newFrame)
{
    ui->Strip->setFrame(newFrame);
}

MYStripAdd::MYStripAdd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MYStripAdd)
{
    ui->setupUi(this);
}

MYStripAdd::~MYStripAdd()
{
    delete ui;
}
