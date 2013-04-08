#include "stdafx.h"
#include "MPGuiTestLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"

USING_NS_CC;

#define PTM_RATIO 32

MPGuiTestLayer::~MPGuiTestLayer() {}

bool MPGuiTestLayer::init() {
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCMenuItemImage *backItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(MPGuiTestLayer::titleCallback));
    
	backItem->setPosition(ccp(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
                               origin.y + backItem->getContentSize().height/2));

    CCMenu* menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    addChild(menu, 1);
    
    CCLabelTTF* label = CCLabelTTF::create("GUI Test Scene", "Arial", TITLE_FONT_SIZE);    
    label->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    addChild(label, 1);
    
    return true;
}

void MPGuiTestLayer::titleCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
    CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
#endif
}