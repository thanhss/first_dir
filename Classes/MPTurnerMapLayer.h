#ifndef MP_TURNER_MAP_LAYER_H
#define MP_TURNER_MAP_LAYER_H

#include "cocos2d.h"
#include "MPLayer.h"

USING_NS_CC;

class MPTurnerMapLayer : public MPLayer
{
public:
    CREATE_FUNC(MPTurnerMapLayer);
    virtual bool init();

private:
    void titleCallback(CCObject * pSender);
    CCSprite * player;
};

#endif
