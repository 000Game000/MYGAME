#ifndef CLOTH_H
#define CLOTH_H

#include "ItemBase.h"
namespace MYGAME{
class Cloth : public ItemBase
{
protected:
    QString img;
public:
    Cloth();
    Cloth(const QString &name, const QString &describe, const QString &itemFunction, const QString &itemType, const QString &location, long long money, long long count,const QString &img);
    QString getImg() const;
    void setImg(const QString &newImg);
};
}
#endif // CLOTH_H
