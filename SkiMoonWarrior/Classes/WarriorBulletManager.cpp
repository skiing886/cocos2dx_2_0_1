#include "GameLayer.h"
#include "MainLayer.h"
#include "TimeLayer.h"
#include "WarriorLayer.h"
#include "WarriorBulletManager.h"

#include "Define.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
bool WarriorBulletManager::init()
{
    bool bRet = false;
    do 
	{
        CC_BREAK_IF(! BasicLayer::init());

		setupViews();

        bRet = true;
    } while (0);

    return bRet;
}

void WarriorBulletManager::setupViews()
{
	do
	{
		//1.将子弹的plist文件加入到CCSpriteFrameCache中
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist", "bullet.png");

		//2.读取其中英雄的子弹，加入CCSpriteBatchNode;注意
		m_pBatchNode = CCSpriteBatchNode::create("bullet.png");

		//3.为CCSpriteBatchNode加入光晕效果
		ccBlendFunc cb = {GL_SRC_ALPHA, GL_ONE};
		m_pBatchNode->setBlendFunc(cb);
		addChild(m_pBatchNode);

		//4.初始化子弹数组
		m_arrBullet = CCArray::create();
		m_arrBullet->retain();

//		schedule(schedule_selector(WarriorBulletManager::addNewBullet), 0.7f);
		schedule(schedule_selector(WarriorBulletManager::moveAllBullets), 0.04f);
		
	}
	while(0);
	
}

void WarriorBulletManager::addNewBullet(CCPoint ptStart)
{
	CCSprite* pBullet = CCSprite::createWithSpriteFrameName("W1.png");
//	pBullet->setPosition(ccp(getSize().width/2, getSize().height/2));
	pBullet->setPosition(ptStart);
	m_arrBullet->addObject(pBullet);

	m_pBatchNode->addChild(pBullet);

}
void WarriorBulletManager::moveAllBullets(float f)
{
	CCSize size = getSize();
	
	CCObject* pObj = NULL;
	CCARRAY_FOREACH(m_arrBullet, pObj)
	{
		CCSprite* pBullet = (CCSprite*)pObj;
		pBullet->setPositionY(pBullet->getPositionY() + 10);
		if(pBullet->getPositionY() > size.height)
		{
			m_pBatchNode->removeChild(pBullet, true);

			m_arrBullet->removeObject(pObj);
		}
	}
}