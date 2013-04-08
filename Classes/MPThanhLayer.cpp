#include "stdafx.h"
#include "MPThanhLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"

USING_NS_CC;

bool MPThanhLayer::init()
{
	CCDirector * director = CCDirector::sharedDirector();

    CCPoint origin = director->getVisibleOrigin();

	float h = director->getVisibleSize().height;
	float w = director->getVisibleSize().width;
    
	// Back button 1
/*	CCMenuItemImage * backBtn = CCMenuItemImage::create(
		"CloseNormal.png", 
		"CloseSelected.png", 
		this, 
		menu_selector(MPThanhLayer::titleCallback));*/

	//Back button 2 (text)
	CCMenuItemLabel* backBtn = CCMenuItemLabel::create(
		CCLabelTTF::create("BACK", "Arial", TITLE_FONT_SIZE),
		this,
		menu_selector(MPThanhLayer::titleCallback));
	
	backBtn->setPosition(
		ccp(origin.x + w - backBtn->getContentSize().width / 2, origin.y + backBtn->getContentSize().height / 2)
	);

	// Clickable
    CCMenu * menu = CCMenu::create(backBtn, NULL);
    menu->setPosition(CCPointZero);
    addChild(menu, 1);
    
	// Screen title
    CCLabelTTF * label = CCLabelTTF::create("Thanh Scene", "Arial", TITLE_FONT_SIZE);
    label->setPosition(ccp(origin.x + w/2,
                           origin.y + h - label->getContentSize().height));
    addChild(label, 1);

	// Player sprite
	player = CCSprite::create("andrew_map/Player.png");
	player->setPosition(ccp(w/4, h/4));
	addChild(player, 1);

	//enable touch
	this->setTouchEnabled(true);
	
	//enable keypad
	this->setKeypadEnabled(true);

	

    return true;
}

void MPThanhLayer::ccTouchesBegan(CCSet* touches, CCEvent* touchEvent)
{
	CCTouch* touch = (CCTouch*)(touches->anyObject());
	CCPoint pTouch = touch->getLocation();

	//player->setPosition(pTouch);
}

void MPThanhLayer::ccTouchesMoved(CCSet* touches, CCEvent* touchEvent)
{
	CCTouch* touch = (CCTouch*)(touches->anyObject());
	CCPoint pTouch = touch->getLocation();

	//player->setPosition(pTouch);
	movePlayer(pTouch);
}

void MPThanhLayer::ccTouchesEnded(CCSet* touches, CCEvent* touchEvent)
{
	CCTouch* touch = (CCTouch*)(touches->anyObject());
	CCPoint pTouch = touch->getLocation();
	
	//player->setPosition(pTouch);
	
}

void MPThanhLayer::keyBackClicked()
{
	CCLOG("Key BACK clicked");
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
}

void MPThanhLayer::keyMenuClicked()
{
	CCLOG("Key MENU clicked");
	//CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
}

void MPThanhLayer::movePlayer(CCPoint p)
{
	CCPoint pMove = player->getPosition();
	if (pMove.x >  p.x)
		pMove.x -= 5;
	else
		pMove.x += 5;
	if (pMove.y >  p.y)
		pMove.y -= 5;
	else
		pMove.y += 5;

	player->setPosition(pMove);
}

void MPThanhLayer::movePlayer(CCPoint p)
{
	CCPoint pMove = player->getPosition();
	if (pMove.x >  p.x)
		pMove.x -= 5;
	else
		pMove.x += 5;
	if (pMove.y >  p.y)
		pMove.y -= 5;
	else
		pMove.y += 5;

	player->setPosition(pMove);
}

void MPThanhLayer::titleCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
}

