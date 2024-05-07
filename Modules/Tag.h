#ifndef TAG_H
#define TAG_H
#include "QString"
#include <QTextStream>
/*
 * 人物标签的类
 * 有标签名称和标签描述
*/
namespace MYGAME{
class Tag
{
private:
    QString name;                                               //标签名称
    QString description;                                        //标签描述
public:
    Tag(const QString &name, const QString &description);
    Tag();
    QString getName() const;
    void setName(const QString &newName);
    QString getDescription() const;
    void setDescription(const QString &newDescription);
    virtual QString save();
    virtual bool load(QTextStream &ts);
};
}
#endif // TAG_H
