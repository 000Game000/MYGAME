#ifndef CLOTHS_H
#define CLOTHS_H
#include <vector>
#include "Item/Cloth.h"
namespace MYGAME{
/*
 * 人物服装类
 */
class Cloths
{
protected:
    Cloth coat;                                         //外衣上
    Cloth pant;                                         //外衣下
    Cloth bra;                                          //内衣上
    Cloth panty;                                        //内衣下
    Cloth shoes;                                        //鞋子
    std::vector<Cloth*> ornaments;                      //物品表列
public:
    Cloths();
    Cloth getCoat() const;
    void setCoat(const Cloth &newCoat);
    Cloth getPant() const;
    void setPant(const Cloth &newPant);
    Cloth getBra() const;
    void setBra(const Cloth &newBra);
    Cloth getPanty() const;
    void setPanty(const Cloth &newPanty);
    Cloth getShoes() const;
    void setShoes(const Cloth &newShoes);
    std::vector<Cloth *> getOrnaments() const;
    std::vector<Cloth*>&getVariableOrnaments();
    void setOrnaments(const std::vector<Cloth *> &newOrnaments);
};
}
#endif // CLOTHS_H
