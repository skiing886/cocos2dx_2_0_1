#include "GameLayer.h"
#include "MainLayer.h"
#include "TimeLayer.h"
#include "WarriorLayer.h"

#include "Define.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
bool WarriorLayer::init()
{
    bool bRet = false;
    do 
	{
        CC_BREAK_IF(! BasicLayer::init());

		setupViews();
		
		setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void WarriorLayer::setupViews()
{
	do
	{
		m_pWarrior = CCSprite::create("ship01.png", CCRectMake(0, 0, 60, 44));
		m_pWarrior->setPosition(ccp(getSize().width/2, getSize().height/2));
		addChild(m_pWarrior);

		CCAnimation* pAnimation = CCAnimation::create();
		pAnimation->setDelayPerUnit(0.1f);
		pAnimation->addSpriteFrame(CCSpriteFrame::create("ship01.png", CCRectMake(0, 0, 60, 44)));
		pAnimation->addSpriteFrame(CCSpriteFrame::create("ship01.png", CCRectMake(60, 0, 60, 44)));
		
		CCAnimate* pAnimate = CCAnimate::create(pAnimation);

		m_pWarrior->runAction(CCRepeatForever::create(pAnimate));

	}
	while(0);
	
}
CCPoint WarriorLayer::getWarriorPosition()
{
	if(!m_pWarrior)
		return ccp(0, 0);
	return m_pWarrior->getPosition();
}
bool WarriorLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint pt = pTouch->locationInView();
	pt.y = getSize().height - pt.y;//£¿£¿£¿£¿
	CCMoveTo* pMoveTo = CCMoveTo::create(0.3f, pt);

	m_pWarrior->runAction(pMoveTo);
	m_pWarrior->setPosition(pTouch->locationInView());

	return true;
}

void WarriorLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,INT_MIN+1,true);
}

void WarriorLayer::tmWaste_Func(float fTime)
{
	
}