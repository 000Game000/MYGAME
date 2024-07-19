#ifndef NODE_H
#define NODE_H

#include <QString>
#include <vector>
#include "Path.h"
namespace MYGAME{
class Node
{
private:
    QString id;                                     //节点id
    QString name;                                   //地点名称
    QString lable;                                  //地点标签
    std::vector<Path*>*pathList;                    //可达地点列表
public:
    Node(QString id,QString name,QString lable);
    QString getId() const;
    void setId(const QString &newId);
    QString getName() const;
    void setName(const QString &newName);
    QString getLable() const;
    void setLable(const QString &newLable);
    std::vector<Path *> *getPathList() const;
    void setPathList(std::vector<Path *> *newPathList);
};
}
#endif // NODE_H
