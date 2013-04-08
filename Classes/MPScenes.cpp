#include "stdafx.h"
#include "MPScenes.h"
#include "MPMacros.h"
#include "MPScenes.h"
#include "MPTitleLayer.h"
#include "MPMapLayer.h"
#include "MPTurnerMapLayer.h"
#include "MPGuiTestLayer.h"
#include "MPBox2DLayer.h"
#include "MPAudioLayer.h"
#include "MPThanhLayer.h"

USING_NS_CC;

cocos2d::CCScene * MPScenes::createTitleScene(){
   	CCScene *scene = CCScene::create();
	CCLayer *layer = MPTitleLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createMapScene(){
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPMapLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createTurnerMapScene(){
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPTurnerMapLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createAudioScene(){
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPAudioLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createBox2DScene(){
    CCScene *scene = CCScene::create();
	CCLayer * layer = MPBox2DLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createGUIScene(){
    CCScene *scene = CCScene::create();
	CCLayer * layer = MPGuiTestLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createThanhScene(){
    CCScene *scene = CCScene::create();
	CCLayer * layer = MPThanhLayer::create();
    scene->addChild(layer);
    return scene;
}