#ifndef MP_THANH_LAYER_H
#define MP_THANH_LAYER_H

#include "cocos2d.h"
#include "MPLayer.h"

USING_NS_CC;

class MPThanhLayer : public MPLayer
{
public:
    CREATE_FUNC(MPThanhLayer);
    virtual bool init();
	void movePlayer(CCPoint p);
	void movePlayer(int direction); //up down left right

private:
	//touch
	void ccTouchesBegan(CCSet* touches, CCEvent* touchEvent);
	void ccTouchesMoved(CCSet* touches, CCEvent* touchEvent);
	void ccTouchesEnded(CCSet* touches, CCEvent* touchEvent);

	void keyBackClicked();
	void keyMenuClicked();

	//key up/down
	//bool ccKeyUp(CCEvent* keyEvent);

	//bool ccKeyDown(CCEvent* keyEvent);

    void titleCallback(CCObject * pSender);
    CCSprite * player;
};

#endif
