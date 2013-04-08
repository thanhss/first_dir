#include "stdafx.h"
#include "MPLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"

USING_NS_CC;

//void MPLayer::addBackButton()
//{
//}

bool MPLayer::init(){
	/*
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
	// Exit button
    
    CCMenuItemImage *backItem = CCMenuItemImage::create(
                                                        "CloseNormal.png",
                                                        "CloseSelected.png",
                                                        this,
                                                        menu_selector(MPMapLayer::titleCallback));
    
	backItem->setPosition(ccp(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
                              origin.y + backItem->getContentSize().height/2));
    
    CCMenu* menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);
    
	// Screen Title
    
    CCLabelTTF* label = CCLabelTTF::create("A Map Scene", "Arial", TITLE_FONT_SIZE);
    label->setPosition(ccp(origin.x + visibleSize.width/2,
                           origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);
    
	// Tile Map
    
    //	CCTMXTiledMap *map = CCTMXTiledMap::create("MP_map/desert.tmx");
	CCTMXTiledMap *map = CCTMXTiledMap::create("andrew_map/andrew_tilemap.tmx");
    this->addChild(map, 0);

    MPMapLayer::antiAliasMap(map);
        
    map->setAnchorPoint(ccp(.5, .5));
    map->setPosition(ccp(visibleSize.width * .5, visibleSize.height * .5));
    map->setScale(.5);


    CCTMXLayer* layer = map->layerNamed("Background");
    assert(layer != NULL);
	
	CCTMXObjectGroup *objectGroup = map->objectGroupNamed("SpawnPointLayer");
	assert(objectGroup != NULL);
	CCSize mapSize = map->getContentSize();
	float mapHeight = mapSize.height;
	float mapWidth = mapSize.width;
	
	player = CCSprite::create("andrew_map/Player.png");
	CCDictionary *spawnPoint = objectGroup->objectNamed("SpawnPoint");
	
	map->addChild(player,1);
	
	const CCString *positionX = spawnPoint->valueForKey("x");
	const CCString *positionY = spawnPoint->valueForKey("y");
	const CCString *objectName = spawnPoint->valueForKey("name");
	
	std::cout << positionX->getCString() << std::endl;
	std::cout << mapHeight - positionY->intValue() % 32 << std::endl;
	std::cout << objectName->getCString() << std::endl;

//	player->setPosition(ccp(positionX,positionY));
*/

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

void MPLayer::antiAliasMap(CCTMXTiledMap * map)
{
    CCArray * pChildrenArray = map->getChildren();
    CCSpriteBatchNode* child = NULL;
    CCObject* pObject = NULL;
    CCARRAY_FOREACH(pChildrenArray, pObject)
    {
        child = (CCSpriteBatchNode*)pObject;
        
        if(!child)
            break;
        
        child->getTexture()->setAntiAliasTexParameters();
    }
}

//void MPLayer::titleCallback(CCObject* pSender)
//{
//	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
//}
