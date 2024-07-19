#include "CrotchTattoo.h"
#include "Modules/Modules.h"
#include "qdebug.h"

#include <QJsonArray>
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
    this->rank=-1;
    this->setMAXEXP();
    this->img="";
}

QJsonObject *CrotchTattoo::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","CrotchTattoo");
    obj->insert("Rank",QString::number(this->rank));
    obj->insert("EXP",QString::number(this->EXP));
    obj->insert("MAXEXP",QString::number(this->MAXEXP));
    obj->insert("Img",this->img);
    QJsonArray*arr=new QJsonArray();
    for(size_t i=0;i<this->sList.size();i++){
        arr->append(this->sList[i]);
    }
    obj->insert("SList",*arr);
    return obj;
}

bool CrotchTattoo::load(QJsonObject obj)
{
    this->rank=obj.value("Rank").toString().toLongLong();
    this->EXP=obj.value("EXP").toString().toLongLong();
    this->MAXEXP=obj.value("MAXEXP").toString().toLongLong();
    this->img=obj.value("Img").toString();
    QJsonValue v=obj.value("SList");
    if(v.isArray()){
        QJsonArray arr=v.toArray();
        for(long long i=0;i<arr.size();i++){
            this->sList.push_back(arr.at(i).toString());
        }
    }
    return true;
}
}
