#ifndef __MP_SCENES_H__
#define __MP_SCENES_H__

#include "cocos2d.h"

USING_NS_CC;

class MPScenes : public cocos2d::CCScene {
public:
    static cocos2d::CCScene * createGUIScene();
    static cocos2d::CCScene * createAudioScene();
    static cocos2d::CCScene * createMapScene();
    static cocos2d::CCScene * createTurnerMapScene();
    static cocos2d::CCScene * createBox2DScene();
    static cocos2d::CCScene * createTitleScene();
	static cocos2d::CCScene * createThanhScene();
};

#endif