#ifndef __MP_BOX2D_LAYER_H__
#define __MP_BOX2D_LAYER_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

class MPBox2DLayer : public cocos2d::CCLayer {
public:
	CREATE_FUNC(MPBox2DLayer);

	virtual ~MPBox2DLayer();

	virtual bool init();  

    void titleCallback(CCObject* pSender);
    
private:
	CCTexture2D * spriteTexture; // weak ref
    b2World * world;

	void initPhysics();
	void addNewSpriteAtPosition(CCPoint p);
    void update(float dt);
    virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);

};

#endif