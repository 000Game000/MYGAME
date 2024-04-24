#include "Modules/Tag.h"
#include "SystemGirlOne.h"
#include "Modules/Cloths.h"
#include "Modules/Attribute.h"
#include "Modules/AttributeAdd.h"
#include "Modules/Position/Anus.h"
#include "Modules/Position/Clit.h"
#include "Modules/Position/Mouth.h"
#include "Modules/Position/Ovary.h"
#include "Modules/Position/Breast.h"
#include "Modules/Position/Nipple.h"
#include "Modules/Position/Vagina.h"
#include "Modules/Position/Uterus.h"
#include "Modules/Position/Urethra.h"
#include "Modules/Position/Bladder.h"

namespace MYGAME {
SystemGirlOne::SystemGirlOne(QDate time,Map*live)
{
    //People 基础属性
    this->name="未柍";
    this->nickName="柍";
    this->claimed="我";
    this->birthday=QDate(time.year()-6,1,1);
    this->occupation="系统娘";
    this->major="无";
    this->attributeList.push_back(new Attribute("智力",999,0));
    this->attributeList.push_back(new Attribute("魅力",150,0));
    this->attributeList.push_back(new AttributeAdd("体质",60,0,60));
    this->attributeList.push_back(new Attribute("敏捷",50,0));
    this->attributeList.push_back(new AttributeAdd("意志",999,0,999));
    this->height=young;
    this->weight=slender;
    this->hairColor.setRgb(21,139,184);
    this->skinColor.setRgb(251,242,227);
    this->LPupilColor.setRgb(6,235,0);
    this->RPupilColor=this->LPupilColor;
    this->tagList.push_back(new Tag("奸商","坑你没商量"));
    this->tagList.push_back(new Tag("猫猫！(？)","真的是猫猫吗?"));
    this->tagList.push_back(new Tag("过度的关心","这是对谁的关心?(反正不是对主角的)"));
    this->tagList.push_back(new Tag("慵懒","这个与懒惰有什么不同呢?"));
    this->positionList.push_back(new Mouth(0,0,100,0));
    this->positionList.push_back(new Breast(1,0,100,0,false,124));
    this->positionList.push_back(new Nipple(2,0,100,0,15,8,1,QColor(255,192,203)));
    this->positionList.push_back(new Clit(3,0,100,0,10,10));
    this->positionList.push_back(new Urethra(-1,0,100,0,3));
    this->positionList.push_back(new Bladder(-2,0,100,0,350));
    this->positionList.push_back(new Vagina(1,0,100,0,40,10,QColor(255,192,203)));
    this->positionList.push_back(new Uterus(-2,0,100,0,5));
    this->positionList.push_back(new Ovary(-3,0,100,0));
    this->positionList.push_back(new Anus(-1,0,100,0,9,500));
    this->describe="一只系统娘";
    this->cloths=Cloths();
    this->live=dynamic_cast<Room*>(live);
    //Girl 属性
    this->id=-1;
    this->lovept=0;
    this->obedience=0;
    this->fornication=0;
    this->desire=0;
    this->sm=0;
    this->exposing=0;
    this->img="";
    this->thought="";
    this->selfIntroduction="宿主？怎么了生病了吗？我帮你看看。不是？自我介绍？呜～虽然不太明白为什么，未柍是系统除制作、商店等核心部分外其它所有系统的掌控者，嘛，虽然是这么说但实际上只安保部分算是完全掌控的。为什么用那种眼神看我？没有骗你喵。喵？！你在掏什么？禁止暴…唉？小鱼干！呜～用这个太无耻了喵。好吧，确实还是有一点权限的，不过我绝对没有改给你的价格喵(看向别处)……为什么要用这个外表？呜～不知道喵，我没有这部分记忆，是谁创造了我，为什么要创造我，为什么…要抛弃我。(未柍弄断一根蓝发，神情低落的看着)喵？我可不是真的猫啊，嘛，这次就特许宿主你的变态行为吧。(未柍毫不理会你的反应直接蜷缩在你的腿上睡了起来，微微惊讶之后你继续抚摸着她)“有一种养女儿的感觉，不过，挺好”猫喜欢睡在纸箱里因为“纸箱”让她有安全感可以毫无顾忌的安睡。";
    this->crotchTattoo=nullptr;
}
}
