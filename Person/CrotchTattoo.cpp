#include "CrotchTattoo.h"
#include "Modules/Modules.h"
#include "qdebug.h"
namespace MYGAME{
long long CrotchTattoo::getRank() const
{
    return rank;
}

void CrotchTattoo::setRank(long long newRank)
{
    rank = newRank;
}

long long CrotchTattoo::getEXP() const
{
    return EXP;
}

void CrotchTattoo::setEXP(long long newEXP)
{
    EXP = newEXP;
}

QString CrotchTattoo::getImg() const
{
    return img;
}

void CrotchTattoo::setImg(const QString &newImg)
{
    img = newImg;
}

std::vector<QString> CrotchTattoo::getSList() const
{
    return sList;
}

std::vector<QString> &CrotchTattoo::getVariableSList()
{
    return sList;
}

void CrotchTattoo::setSList(const std::vector<QString> &newSList)
{
    sList = newSList;
}

void CrotchTattoo::setMAXEXP()
{
    const long long num[3] = { 10,30,60 };
    if (abs(this->rank) < 3) {
        this->MAXEXP=num[abs(this->rank)];
    }
    else if (abs(this->rank) == 3) {
        this->MAXEXP=(abs(this->rank) - 2) * 100;
    }
    else {
        long long exp = 0;
        for (long long i = 0; i <abs(this->rank)-1; i++) {
            exp += i * 100;
        }
        this->MAXEXP=exp;
    }
}

long long CrotchTattoo::getMAXEXP() const
{
    return MAXEXP;
}

CrotchTattoo::CrotchTattoo()
{
    this->EXP=0;
    this->rank=0;
    this->setMAXEXP();
    this->img="";
}

QString CrotchTattoo::save()
{

    QString str="\nrank:"+QString::number(this->rank)+"\nEXP:"+QString::number(this->EXP)+"\nMAXEXP:"+QString::number(this->MAXEXP)+
                  "\nimg:"+img;
    str+="\n数量:"+QString::number(sList.size());
    for(size_t i=0;i<this->sList.size();i++){
        str+="\n"+this->sList[i];
    }
    return str;
}

bool CrotchTattoo::load(QTextStream &ts)
{
    this->rank=getValue(ts.readLine()).toLongLong();
    this->EXP=getValue(ts.readLine()).toLongLong();;
    this->MAXEXP=getValue(ts.readLine()).toLongLong();
    this->img=getValue(ts.readLine());
    size_t max=getValue(ts.readLine()).toLongLong();
    for(size_t i=0;i<max;i++){
        this->sList.push_back(getValue(ts.readLine()));
    }
    return true;
}
}
