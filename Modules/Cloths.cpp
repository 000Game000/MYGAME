#include "Cloths.h"
namespace MYGAME{
Cloth Cloths::getCoat() const
{
    return coat;
}

void Cloths::setCoat(const Cloth &newCoat)
{
    coat = newCoat;
}

Cloth Cloths::getPant() const
{
    return pant;
}

void Cloths::setPant(const Cloth &newPant)
{
    pant = newPant;
}

Cloth Cloths::getBra() const
{
    return bra;
}

void Cloths::setBra(const Cloth &newBra)
{
    bra = newBra;
}

Cloth Cloths::getPanty() const
{
    return panty;
}

void Cloths::setPanty(const Cloth &newPanty)
{
    panty = newPanty;
}

Cloth Cloths::getShoes() const
{
    return shoes;
}

void Cloths::setShoes(const Cloth &newShoes)
{
    shoes = newShoes;
}

std::vector<Cloth *> Cloths::getOrnaments() const
{
    return ornaments;
}

std::vector<Cloth *> &Cloths::getVariableOrnaments()
{
    return ornaments;
}

void Cloths::setOrnaments(const std::vector<Cloth *> &newOrnaments)
{
    ornaments = newOrnaments;
}

Cloths::Cloths()
{

}
}
