#include "GameLayer.h"

using namespace cocos2d;

GameLayer::GameLayer()
{
	bkg1 = NULL;
	bkg2 = NULL;

	pPlaneLayer = NULL;
}
GameLayer::~GameLayer()
{
	
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

		//png加入全局cache
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("AirplaneRes/ui/shoot_background.plist");

		//加载bkg1
		bkg1 = CCSprite::create(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
		bkg1->setAnchorPoint(ccp(0, 0));
		bkg1->setPosition(ccp(0, 0));
		addChild(bkg1);

		bkg2 = CCSprite::create(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
		bkg2->setAnchorPoint(ccp(0, 0));
		bkg2->setPosition(ccp(0, 0));
		addChild(bkg2);

		//add plane to game
		this->pPlaneLayer = PlaneLayer::create();
		//CC_BREAK_IF(pPlaneLayer);
		this->addChild(pPlaneLayer);

		//add bullet layer to game
		pBulletLayer = BulletLayer::create();
		addChild(pBulletLayer);
		pBulletLayer->StartShoot(1);

		schedule(schedule_selector(GameLayer::bkgMove), 0.001f);
        bRet = true;
    } while (0);

    return bRet;
}

void GameLayer::bkgMove(float dt)
{

   bkg1->setPositionY(bkg1->getPositionY() - 2);
   bkg2->setPositionY(bkg1->getPositionY() + bkg1->getContentSize().height - 2);

   if(bkg2->getPositionY() == 0)
	   bkg1->setPositionY(0);

}

