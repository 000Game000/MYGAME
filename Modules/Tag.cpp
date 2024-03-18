#include "Tag.h"

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

Tag::Tag(const QString &name, const QString &description) : name(name),
    description(description)
{}
