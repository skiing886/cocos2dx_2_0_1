#include "GameLayer.h"
#include "MainLayer.h"
#include "ScoreLayer.h"
#include "TimeLayer.h"
#include "PauseLayer.h"
#include "WarriorLayer.h"

#include "SLog.h"
#include "Define.h"

using namespace cocos2d;

CCScene* GameLayer::scene()
{
    CCScene * pSc = NULL;
    do 
    {
        // 'scene' is an autorelease object
        pSc = CCScene::create();
        CC_BREAK_IF(! pSc);

        // 'layer' is an autorelease object
        GameLayer *pLayer = GameLayer::create();
        CC_BREAK_IF(! pLayer);

        // add layer as a child to scene
        pSc->addChild(pLayer);
    } while (0);

    // return the scene
    return pSc;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
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

void GameLayer::setupViews()
{
	do
	{
		CCSprite* pBg1 = CCSprite::create("bg01.jpg");
		CC_BREAK_IF(!pBg1);
		pBg1->setAnchorPoint(CCPointZero);

		CCSprite* pBg2 = CCSprite::create("bg01.jpg");
		CC_BREAK_IF(!pBg2);
		pBg2->setAnchorPoint(CCPointZero);

		pBg1->setPosition(ccp(0, 0));
		pBg2->setPosition(ccp(0, 576));

		addChild(pBg1, 0, BG01_TAG);
		addChild(pBg2, 0, BG02_TAG);

		schedule(schedule_selector(GameLayer::bgScroll_Func), 0.05f);

		//加入飞船
		m_pWarrior = WarriorLayer::create();
		m_pWarrior->setPosition(ccp(0, 0));
		addChild(m_pWarrior, 0, WARRIOR_LAYER_TAG);

		//加入子弹
		m_pBulletMgr = WarriorBulletManager::create();
		addChild(m_pBulletMgr);

		//加入分数层
		ScoreLayer* pScore = ScoreLayer::create();
		pScore->setAnchorPoint(ccp(0, 1));
		pScore->setPosition(10, getSize().height - 20);
		addChild(pScore);

		//加入时间层
		TimeLayer* pTime = TimeLayer::create();
		pTime->setAnchorPoint(ccp(0, 1));
		pTime->setPosition(getSize().width/2, getSize().height - 20);
		addChild(pTime);

		//加入暂停按钮
		CCMenuItemImage* pBtnPause = CCMenuItemImage::create("pause.png", "pause.png", this, 
																menu_selector(GameLayer::pause_Func));
		CCMenu* pMenu = CCMenu::create(pBtnPause, NULL);
		pMenu->setAnchorPoint(ccp(0, 0));
		pMenu->setPosition(ccp(getSize().width-40, 40));
		addChild(pMenu);

		//加入暂停层并隐藏
		PauseLayer* pLayerPause = PauseLayer::create();
		//pLayerPause->setAnchorPoint(ccp(0, 1));
		pLayerPause->setPosition(CCPointZero);
		addChild(pLayerPause, 10, PAUSE_LAYER_TAG);
		pLayerPause->setVisible(false);

		//为飞船发射子弹
		schedule(schedule_selector(GameLayer::warriorFire_Func), 0.3f);
	}
	while(0);
	
}

void GameLayer::warriorFire_Func(float t)
{
	CCPoint pt = m_pWarrior->getWarriorPosition();
	if(pt.y + 30 >= getSize().height)
		return;
	m_pBulletMgr->addNewBullet(pt);
}

void GameLayer::bgScroll_Func(float fTime)
{
	CCSprite* pBg1 = (CCSprite*)getChildByTag(BG01_TAG);
	CCSprite* pBg2 = (CCSprite*)getChildByTag(BG02_TAG);

	pBg1->setPositionY(pBg1->getPositionY() - 10);
	pBg2->setPositionY(pBg1->getPositionY() + 576);
	if(pBg2->getPositionY() <= 0)
		pBg1->setPositionY(0);

}
void GameLayer::pause_Func(CCObject* pSender)
{
	//显示暂停层
	PauseLayer* pLayerPause = (PauseLayer*)getChildByTag(PAUSE_LAYER_TAG);
	if(!pLayerPause)
	{
		SLog::Log("GameLayer::pause_Func() : pLayerPause = NULL");
		return;
	}
	pLayerPause->setVisible(true);

	//暂停当前场景
	CCDirector::sharedDirector()->pause();

	//暂停背景音乐
	if(SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();

}

