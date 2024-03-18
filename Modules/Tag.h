#ifndef TAG_H
#define TAG_H
#include "QString"
/*
 * 人物标签的类
 * 有标签名称和标签描述
*/
class Tag
{
private:
    QString name;                                               //标签名称
    QString description;                                        //标签描述
public:
    Tag(const QString &name, const QString &description);
    QString getName() const;
    void setName(const QString &newName);
    QString getDescription() const;
    void setDescription(const QString &newDescription);
};

#endif // TAG_H
