#include "CrotchTattoo.h"
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

CrotchTattoo::CrotchTattoo()
{

}
}
