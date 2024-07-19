#include "Node.h"
namespace MYGAME{
QString Node::getId() const
{
    return id;
}

void Node::setId(const QString &newId)
{
    id = newId;
}

QString Node::getName() const
{
    return name;
}

void Node::setName(const QString &newName)
{
    name = newName;
}

QString Node::getLable() const
{
    return lable;
}

void Node::setLable(const QString &newLable)
{
    lable = newLable;
}

std::vector<Path *> *Node::getPathList() const
{
    return pathList;
}

void Node::setPathList(std::vector<Path *> *newPathList)
{
    pathList = newPathList;
}

Node::Node(QString id,QString name,QString lable)
    :id(id),name(name),lable(lable)
{

}
}
