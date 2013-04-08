#ifndef HelloCpp_MPTitleLayer_h
#define HelloCpp_MPTitleLayer_h

#include "cocos2d.h"

USING_NS_CC;

class MPTitleLayer : public cocos2d::CCLayer{
public:
    CREATE_FUNC(MPTitleLayer);
    
    virtual bool init();
    
    void menuCloseCallback(CCObject* pSender);
    
    void selectBox2D(CCObject* pSender);
    
    void selectGuiTest(CCObject* pSender);
    
    void selectAudio(CCObject* pSender);
    
    void selectMap(CCObject* pSender);

    void selectTurnerMap(CCObject* pSender);

	void selectThanh(CCObject* pSender);

};

#endif
