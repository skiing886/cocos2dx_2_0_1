#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Utils.h"
#include "BulletLayer.h"
#include "PlaneLayer.h"


using namespace cocos2d;


//PlaneLayer* PlaneLayer::sharePlane = NULL;

BulletLayer::BulletLayer()
{
	m_pAllBullet = CCArray::create();
	m_pAllBullet->retain();
}
BulletLayer::~BulletLayer()
{
	m_pAllBullet->release();
	m_pAllBullet = NULL;
}


// on "init" you need to initialize your instance
bool BulletLayer::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

		CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->textureForKey("AirplaneRes/ui/shoot.png");
		m_pBatchNode = CCSpriteBatchNode::create(pTexture);
		this->addChild(m_pBatchNode);
		
        bRet = true;
    } while (0);

    return bRet;
}

void BulletLayer::AddBullet(float dt)
{
	CCSprite* pBullet = CCSprite::createWithSpriteFrameName("bullet1.png");
	CCPoint PlanePos = PlaneLayer::sharePlane->getChildByTag(PLANE_TAG)->getPosition();
	CCPoint pBulletPos = ccp(PlanePos.x, 
						PlanePos.y + PlaneLayer::sharePlane->getChildByTag(PLANE_TAG)->getContentSize().height/2);
	pBullet->setPosition(pBulletPos);

	float fHeight = CCDirector::sharedDirector()->getWinSize().height - pBulletPos.y;
	float fV = 420/1;//420 pix per second
	float fTime = fHeight/fV;

	CCFiniteTimeAction* pActionMove = CCMoveTo::create(fTime, ccp(PlanePos.x, fHeight + pBulletPos.y));
	CCFiniteTimeAction* pActionDone = CCCallFuncN::create(this, callfuncN_selector(BulletLayer::DeleteBullet));

	CCSequence* pSequence = CCSequence::create(pActionMove, pActionDone);
	pBullet->runAction(pSequence);

	m_pAllBullet->addObject(pBullet);


	m_pBatchNode->addChild(pBullet);
}

//×Óµ¯³¬³öÆÁÄ»£¬ÒÆ³ý
void BulletLayer::DeleteBullet(CCNode* pSender)
{
	CCSprite* pBullet = (CCSprite*)pSender;
	m_pAllBullet->removeObject(pBullet);
	this->removeChild(pBullet, true);
}

//×Óµ¯ÓëµÐ»úÅö×²£¬ÒÆ³ý
void BulletLayer::RemoveBullet(CCSprite* pBullet)
{
	if(pBullet != NULL)
	{
		m_pAllBullet->removeObject(pBullet);
		removeChild(pBullet, true);
	}
}

void BulletLayer::StartShoot(float fDelay)
{
	this->schedule(schedule_selector(BulletLayer::AddBullet), 0.4f, kCCRepeatForever, fDelay);
}
void BulletLayer::StopShoot()
{
	this->unschedule(schedule_selector(BulletLayer::AddBullet));
}


