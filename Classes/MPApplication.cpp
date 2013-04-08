#include "stdafx.h"
#include "MPApplication.h"
#include "SimpleAudioEngine.h"
#include "MPMacros.h"
#include "MPScenes.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

MPApplication::MPApplication() {}

MPApplication::~MPApplication() {
    SimpleAudioEngine::sharedEngine()->end();
}

bool MPApplication::applicationDidFinishLaunching() 
{
    // initialize director
    CCDirector * director = CCDirector::sharedDirector();
    CCEGLView * eglView = CCEGLView::sharedOpenGLView();
    director->setOpenGLView(eglView);
	
    // Set the design resolution
    eglView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
    CCSize frameSize = eglView->getFrameSize();
    vector<string> searchPath;

	CCLOG("%f", designResolutionSize.width);

    // In this demo, we select resource according to the frame's height.
    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
    // We use the ratio of resource's height to the height of design resolution,
    // this can make sure that the resource's height could fit for the height of design resolution.

    // if the frame's height is larger than the height of medium resource size, select large resource.
    if (frameSize.height > mediumResource.size.height) {
        searchPath.push_back(largeResource.directory);
        director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small resource size, select medium resource.
    else if (frameSize.height > smallResource.size.height) {
        searchPath.push_back(mediumResource.directory);
        director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium resource size, select small resource.
    else {
        searchPath.push_back(smallResource.directory);
        director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }
    // set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);	
    // turn on display FPS
    director->setDisplayStats(true);
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    // create a scene. it's an autorelease object
    CCScene *pScene = MPScenes::createTitleScene();
    director->runWithScene(pScene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void MPApplication::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void MPApplication::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}