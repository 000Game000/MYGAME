#include "MYFunctions.h"

namespace MYGAME {
QString getSPosition(Map*map){
    QString Slive=map->getName();
    if(map->getSuperiorMap()!=nullptr){
        Slive=getSPosition(map->getSuperiorMap())+"\\"+Slive;
    }
    return Slive;
}
}
