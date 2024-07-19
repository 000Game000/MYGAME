#include "Tag.h"
namespace MYGAME {


QString Tag::getName() const
{
    return name;
}

void Tag::setName(const QString &newName)
{
    name = newName;
}

QString Tag::getDescription() const
{
    return description;
}

void Tag::setDescription(const QString &newDescription)
{
    description = newDescription;
}

QJsonObject*Tag::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Tag");
    obj->insert("Name",this->name);
    obj->insert("Description",this->description);
    return obj;
}

bool Tag::load(QJsonObject obj)
{
    this->name=obj.value("Name").toString();
    this->description=obj.value("Description").toString();
    return true;
}

Tag::Tag(const QString &name, const QString &description) : name(name),
    description(description)
{}

Tag::Tag()
{

}
}
