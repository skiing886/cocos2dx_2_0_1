#include "MainLayer.h"
#include "AboutLayer.h"
#include "OptionLayer.h"
#include "GameLayer.h"

using namespace cocos2d;

CCScene* MainLayer::scene()
{
    CCScene * pSc = NULL;
    do 
    {
        // 'scene' is an autorelease object
        pSc = CCScene::create();
        CC_BREAK_IF(! pSc);

        // 'layer' is an autorelease object
        MainLayer *pLayer = MainLayer::create();
        CC_BREAK_IF(! pLayer);

        // add layer as a child to scene
        pSc->addChild(pLayer);
    } while (0);

    // return the scene
    return pSc;
}

// on "init" you need to initialize your instance
bool MainLayer::init()
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

void MainLayer::setupViews()
{
	//��ӱ���ͼƬ
	setBackImage("loading.png");

	//��ӿ�ʼ��ť
	CCSprite* pStartNormal = CCSprite::create("menu.png", CCRectMake(0, 0, 126, 33));
	CCSprite* pStartPressed = CCSprite::create("menu.png", CCRectMake(0, 33, 126, 33));
	CCSprite* pStartDisabled = CCSprite::create("menu.png", CCRectMake(0, 66, 126, 33));
	CCMenuItemSprite* pBtnStart = CCMenuItemSprite::create(pStartNormal, pStartPressed, pStartDisabled, this, menu_selector(MainLayer::StartMenu_Func));

	//���ѡ�ť
	CCSprite* pOptNormal = CCSprite::create("menu.png", CCRectMake(126, 0, 126, 33));
	CCSprite* pOptPressed = CCSprite::create("menu.png", CCRectMake(126, 33, 126, 33));
	CCSprite* pOptDisabled = CCSprite::create("menu.png", CCRectMake(126, 66, 126, 33));
	CCMenuItemSprite* pBtnOpt = CCMenuItemSprite::create(pOptNormal, pOptPressed, pOptDisabled, this, menu_selector(MainLayer::OptMenu_Func));

	//��ӹ��ڰ�ť
	CCSprite* pAboutNormal = CCSprite::create("menu.png", CCRectMake(252, 0, 126, 33));
	CCSprite* pAboutPressed = CCSprite::create("menu.png", CCRectMake(252, 33, 126, 33));
	CCSprite* pAboutDisabled = CCSprite::create("menu.png", CCRectMake(252, 66, 126, 33));
	CCMenuItemSprite* pBtnAbout = CCMenuItemSprite::create(pAboutNormal, pAboutPressed, pAboutDisabled, this, menu_selector(MainLayer::AboutMenu_Func));

	//���˵���������
	CCMenu* pMenu = CCMenu::create(pBtnStart, pBtnOpt, pBtnAbout, NULL);
	pMenu->alignItemsVerticallyWithPadding(10);//�˵����մ�ֱ���10���ض���
	addChild(pMenu);

	//���logo
	CCSprite* pLogo = CCSprite::create("logo.png");
	pLogo->setPosition(ccp(getSize().width/2, getSize().height/2 + 150));
	addChild(pLogo);
}

void MainLayer::StartMenu_Func(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, GameLayer::scene()));
}

void MainLayer::OptMenu_Func(CCObject* pSender)
{
	CCLOG("opt");
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, OptionLayer::scene()));
}
void MainLayer::AboutMenu_Func(CCObject* pSender)
{
	CCLOG("about");

	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, AboutLayer::scene()));
}

void MainLayer::onEnter()
{
	CCLayer::onEnter();

	CCLOG("onEnter");

	//���뱳������
	bool bFlag = false;//Ϊfalse��Ҫ��������
	bFlag = CCUserDefault::sharedUserDefault()->getBoolForKey("music_not_play");
	if(!bFlag)
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/mainMainMusic.mp3", true);
	else
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();

	
}

