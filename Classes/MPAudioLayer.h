#ifndef HelloCpp_MPAudioLayer_h
#define HelloCpp_MPAudioLayer_h

#include "cocos2d.h"

USING_NS_CC;

class MPAudioLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(MPAudioLayer);
    
    cocos2d::CCSprite* player;
    
	virtual bool init();

    void titleCallback(CCObject* pSender);
    
    static bool getPaused();
    
    static void setPaused();
    
private:
    virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);
    
    static bool paused;
};




#endif
