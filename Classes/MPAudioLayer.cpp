#include "stdafx.h"
#include "MPScenes.h"
#include "MPMacros.h"
#include "MPAudioLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


using namespace CocosDenshion;

bool MPAudioLayer::paused = false;

bool MPAudioLayer::init(){

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    //enable touch on screen
    this->setTouchEnabled(true);
    //this->setTouchMode(cocos2d::ccTouchesMode::kCCTouchesOneByOne);

    CCMenuItemImage *backItem = CCMenuItemImage::create(
                                                    "CloseNormal.png",
                                                    "CloseSelected.png",
                                                    this,
                                                    menu_selector(MPAudioLayer::titleCallback));

    backItem->setPosition(ccp(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
                          origin.y + backItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);

    //Scene Title

    CCLabelTTF* label = CCLabelTTF::create("Audio Scene", "Arial", TITLE_FONT_SIZE);

    label->setPosition(ccp(origin.x + visibleSize.width/2,
                       origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    player = CCSprite::create("dragon_sign.png");

    //player->setContentSize(CCSizeMake(player->getContentSize().width*3, player->getContentSize().height*3));
    player ->setPosition(ccp(visibleSize.width/3, visibleSize.height/3));

    this->addChild(player, 1);

    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("background.mp3");
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3", true);

    return true;
}

void MPAudioLayer::titleCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}


bool MPAudioLayer::getPaused(){
    return paused;
}

void MPAudioLayer::setPaused(){
    paused = !paused;
}

void MPAudioLayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    bool isPaused = getPaused();
    if(isPaused == true){
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
        setPaused();
    }
    else{
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
        setPaused();
    }
}
