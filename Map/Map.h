#ifndef MAP_H
#define MAP_H
#include <QString>
namespace MYGAME {
/*
 *地图类
 */
class Map
{
protected:
    QString name;                                        //区域名称
    std::vector<Map*>*list;                              //下级区域表列,当没有下级时,此项为空
    QString img;                                         //地区图片
    QString type;                                        //层级
    Map*superiorMap;                                     //上级区域.当为顶级区域时,此项为空
public:
    Map();
    Map(const QString &name, std::vector<Map *> *list, const QString &img, const QString &type, Map *superiorMap);

    QString getName() const;
    void setName(const QString &newName);
    std::vector<Map *> *getList() const;
    void setList(std::vector<Map *> *newList);
    Map *getSuperiorMap() const;
    void setSuperiorMap(Map *newSuperiorMap);
    virtual void show();
    QString getImg() const;
    void setImg(const QString &newImg);
    QString getType() const;
    void setType(const QString &newType);
};
}
#endif // MAP_H
