#ifndef GIRL_H
#define GIRL_H

#include "People.h"
#include "CrotchTattoo.h"
namespace MYGAME{
/*
 * 妹子们的基类
 */
class Girl : public People
{
protected:
    long long id;                                           //人物id
    long long lovept;                                       //好感度
    long long obedience;                                    //服从度
    long long fornication;                                  //淫乱度
    long long desire;                                       //欲望100满值
    long long sm;                                           //sm度负数为m度,正数为s度
    long long exposing;                                     //露出快感
    QString img;                                            //人物立绘
    QString thought;                                        //人物心里话
    QString selfIntroduction;                               //自我介绍
    CrotchTattoo*crotchTattoo;                              //淫纹
public:
    Girl();
    long long getId() const;
    void setId(long long newId);
    long long getLovept() const;
    void setLovept(long long newLovept);
    long long getObedience() const;
    void setObedience(long long newObedience);
    long long getFornication() const;
    void setFornication(long long newFornication);
    QString getImg() const;
    void setImg(const QString &newImg);
    QString getThought() const;
    void setThought(const QString &newThought);
    QString getSelfIntroduction() const;
    void setSelfIntroduction(const QString &newSelfIntroduction);
    CrotchTattoo *getCrotchTattoo() const;
    CrotchTattoo *getVariableCrotchTattoo();
    void setCrotchTattoo(CrotchTattoo *newCrotchTattoo);
    long long getSm() const;
    void setSm(long long newSm);
    long long getExposing() const;
    void setExposing(long long newExposing);
};
}
#endif // GIRL_H
