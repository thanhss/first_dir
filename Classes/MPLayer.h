#ifndef MP_LAYER_H
#define MP_LAYER_H

#include "cocos2d.h"

USING_NS_CC;

class MPLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

protected:
    void antiAliasMap(CCTMXTiledMap * map);

private:
//    void titleCallback(CCObject * pSender);
};

#endif
