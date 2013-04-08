#include "stdafx.h"
#include "MPTurnerMapLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"

USING_NS_CC;

bool MPTurnerMapLayer::init()
{
	CCDirector * director = CCDirector::sharedDirector();

    CCPoint origin = director->getVisibleOrigin();

//	CCLOG("%.2f", origin.x);
//	CCLOG("%.2f", origin.y);

	float h = director->getVisibleSize().height;
	float w = director->getVisibleSize().width;
    
	// Back button
    CCMenuItemImage * backBtn = CCMenuItemImage::create(
		"CloseNormal.png", 
		"CloseSelected.png", 
		this, 
		menu_selector(MPTurnerMapLayer::titleCallback));
	backBtn->setPosition(
		ccp(origin.x + w - backBtn->getContentSize().width / 2, origin.y + backBtn->getContentSize().height / 2)
	);

	// Clickable
    CCMenu * menu = CCMenu::create(backBtn, NULL);
    menu->setPosition(CCPointZero);
    addChild(menu, 1);
    
	// Screen title
    CCLabelTTF * label = CCLabelTTF::create("Turner Scene", "Arial", TITLE_FONT_SIZE);
    label->setPosition(ccp(origin.x + w/2,
                           origin.y + h - label->getContentSize().height));
    addChild(label, 1);

	// Player sprite
	player = CCSprite::create("andrew_map/Player.png");
	player->setPosition(ccp(w/2, h/2));
	addChild(player, 1);

/*
    CCSprite *tile = layer->tileAt(ccp(5,6));
    assert(tile != NULL);
    
    layer->removeTileAt(ccp(5, 6));
    
    CCActionInterval*  actionBy = CCMoveBy::create(2, ccp(visibleSize.width * .5, visibleSize.height * .5));
    map->runAction(actionBy);
    
    CCActionInterval* action = CCScaleBy::create(2, 2);
    map->runAction(action);
*/
    
    
/*
    CCSize s = layer->getLayerSize();
    for (int x = 2; x < s.width; x++) {
        for (int y = 0; y < s.height; y++) {
            layer->removeTileAt(ccp(x, y));
        }
    }
*/
    return true;
}

void MPTurnerMapLayer::titleCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
}

