#include "stdafx.h"
#include "MPBox2DLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"
#include "Box2D/Box2D.h"
#include "VisibleRect.h"
//#include "cocos-ext.h"
#include "physics_nodes/CCPhysicsSprite.h"

USING_NS_CC_EXT;

#define PTM_RATIO 32

enum {
    parentNodeTag = 1,
};

MPBox2DLayer::~MPBox2DLayer() {
    CC_SAFE_DELETE(world);
}

bool MPBox2DLayer::init() {
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCMenuItemImage *backItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(MPBox2DLayer::titleCallback));
    
    backItem->setPosition(ccp(origin.x + visibleSize.width - backItem->getContentSize().width/2, origin.y + backItem->getContentSize().height/2));

    CCMenu* menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    addChild(menu, 1);
    
    CCLabelTTF* titleLabel = CCLabelTTF::create("Box 2D Scene", "Arial",TITLE_FONT_SIZE);
    titleLabel->setPosition(ccp(origin.x + visibleSize.width/2, origin.y + visibleSize.height - titleLabel->getContentSize().height));
    addChild(titleLabel, 1);

	CCLabelTTF * label = CCLabelTTF::create("Tap screen", "Marker Felt", 32);
    addChild(label, 0);
    label->setColor(ccc3(0,0,255));
    label->setPosition(ccp( VisibleRect::center().x, VisibleRect::top().y-50));

	initPhysics();

	CCSpriteBatchNode * parent = CCSpriteBatchNode::create("blocks.png", 100);
    spriteTexture = parent->getTexture();

	addChild(parent, 0, parentNodeTag);

	addNewSpriteAtPosition(VisibleRect::center());
    
    scheduleUpdate();

	setTouchEnabled(true);
	//setAccelerometerEnabled( true );

    return true;
}

void MPBox2DLayer::titleCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
}

void MPBox2DLayer::initPhysics() {
    b2Vec2 gravity;
    gravity.Set(0.0f, -10.0f);
    world = new b2World(gravity);

    // Do we want to let bodies sleep?
    world->SetAllowSleeping(true);

    world->SetContinuousPhysics(true);

    // m_debugDraw = new GLESDebugDraw( PTM_RATIO );
    // world->SetDebugDraw(m_debugDraw);

    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    // flags += b2Draw::e_jointBit;
    // flags += b2Draw::e_aabbBit;
    // flags += b2Draw::e_pairBit;
    // flags += b2Draw::e_centerOfMassBit;
    // m_debugDraw->SetFlags(flags);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0); // bottom-left corner

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world->CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2EdgeShape groundBox;

    // bottom
    groundBox.Set(b2Vec2(VisibleRect::leftBottom().x/PTM_RATIO,VisibleRect::leftBottom().y/PTM_RATIO), b2Vec2(VisibleRect::rightBottom().x/PTM_RATIO,VisibleRect::rightBottom().y/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);

    // top
    groundBox.Set(b2Vec2(VisibleRect::leftTop().x/PTM_RATIO,VisibleRect::leftTop().y/PTM_RATIO), b2Vec2(VisibleRect::rightTop().x/PTM_RATIO,VisibleRect::rightTop().y/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);

    // left
    groundBox.Set(b2Vec2(VisibleRect::leftTop().x/PTM_RATIO,VisibleRect::leftTop().y/PTM_RATIO), b2Vec2(VisibleRect::leftBottom().x/PTM_RATIO,VisibleRect::leftBottom().y/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);

    // right
    groundBox.Set(b2Vec2(VisibleRect::rightBottom().x/PTM_RATIO,VisibleRect::rightBottom().y/PTM_RATIO), b2Vec2(VisibleRect::rightTop().x/PTM_RATIO,VisibleRect::rightTop().y/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
}

void MPBox2DLayer::addNewSpriteAtPosition(CCPoint p) {
    CCLOG("Add sprite %0.2f x %02.f",p.x,p.y);
    
    // Define the dynamic body.
    //Set up a 1m squared box in the physics world
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(p.x/PTM_RATIO, p.y/PTM_RATIO);

    b2Body * body = world->CreateBody(&bodyDef);
    
    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(.5f, .5f); //These are mid points for our 1m box
    
    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;    
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);    
    
    CCNode * parent = this->getChildByTag(parentNodeTag);
    
    // We have a 64x64 sprite sheet with 4 different 32x32 images.  The following code is
    // just randomly picking one of the images
    int idx = (CCRANDOM_0_1() > .5 ? 0:1);
    int idy = (CCRANDOM_0_1() > .5 ? 0:1);
    CCPhysicsSprite *sprite = CCPhysicsSprite::createWithTexture(spriteTexture,CCRectMake(32 * idx, 32 * idy, 32, 32));
    parent->addChild(sprite);
    sprite->setB2Body(body);
    sprite->setPTMRatio(PTM_RATIO);
    sprite->setPosition( ccp( p.x, p.y) );
}


void MPBox2DLayer::update(float dt) {
    // It is recommended that a fixed time step is used with Box2D for stability
    // of the simulation, however, we are using a variable time step here.
    // You need to make an informed choice, the following URL is useful
    // http://gafferongames.com/game-physics/fix-your-timestep/
    
    int velocityIterations = 8;
    int positionIterations = 1;

    // Instruct the world to perform a single step of simulation. It is
    // generally best to keep the time step and iterations fixed.
    world->Step(dt, velocityIterations, positionIterations);
}

void MPBox2DLayer::ccTouchesEnded(CCSet* touches, CCEvent* event) {
    // Add a new body/atlas sprite at the touched location
    CCSetIterator it;
    CCTouch* touch;

    for( it = touches->begin(); it != touches->end(); it++) {
        touch = (CCTouch*)(*it);

        if(!touch) {
		    break;
		}

        CCPoint location = touch->getLocation();
    
        addNewSpriteAtPosition( location );
    }
}