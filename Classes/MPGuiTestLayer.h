#ifndef __MP_GUI_TEST_LAYER_H__
#define __MP_GUI_TEST_LAYER_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

class MPGuiTestLayer : public cocos2d::CCLayer {
public:
	CREATE_FUNC(MPGuiTestLayer);

	virtual ~MPGuiTestLayer();

	virtual bool init();  

    void titleCallback(CCObject* pSender);
    
private:
	CCTexture2D* m_pSpriteTexture; // weak ref
    b2World* world;

	void initPhysics();
};

#endif