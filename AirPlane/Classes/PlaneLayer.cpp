#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "PlaneLayer.h"
#include "Utils.h"

using namespace cocos2d;


PlaneLayer* PlaneLayer::sharePlane = NULL;

PlaneLayer::PlaneLayer()
{

}
PlaneLayer::~PlaneLayer()
{

}

//we can get a autorelease object
PlaneLayer* PlaneLayer::create()
{
	PlaneLayer* pPlaneLayer = new PlaneLayer();
	if(pPlaneLayer && pPlaneLayer->init())
	{
		pPlaneLayer->autorelease();//add it to auto release pool 
		sharePlane = pPlaneLayer;

		return pPlaneLayer;
	}
	else
	{
		CC_SAFE_DELETE(pPlaneLayer);
		return NULL;
	}
}

// on "init" you need to initialize your instance
bool PlaneLayer::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		//png加入全局cache
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("AirplaneRes/ui/shoot.plist");

		CCSprite* plane = CCSprite::create(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero1.png"));
		plane->setPosition(ccp(winSize.width/2, plane->getContentSize().height/2));
		//this->addChild(plane);

		CCBlink* pBlink = CCBlink::create(1, 3);

		CCAnimation* pAnimation = CCAnimation::create();
		pAnimation->setDelayPerUnit(0.01f);
		pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero1.png"));
		pAnimation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero2.png"));

		CCAnimate* pAnimate = CCAnimate::create(pAnimation);

		plane->runAction(pBlink);
		plane->runAction(CCRepeatForever::create(pAnimate));

		addChild(plane, 0, PLANE_TAG);
		

        bRet = true;
    } while (0);

    return bRet;
}


