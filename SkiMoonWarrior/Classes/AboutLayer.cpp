#include "AboutLayer.h"
#include "MainLayer.h"

using namespace cocos2d;

CCScene* AboutLayer::scene()
{
    CCScene * pSc = NULL;
    do 
    {
        // 'scene' is an autorelease object
        pSc = CCScene::create();
        CC_BREAK_IF(! pSc);

        // 'layer' is an autorelease object
        AboutLayer *pLayer = AboutLayer::create();
        CC_BREAK_IF(! pLayer);

        // add layer as a child to scene
        pSc->addChild(pLayer);
    } while (0);

    // return the scene
    return pSc;
}

// on "init" you need to initialize your instance
bool AboutLayer::init()
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

void AboutLayer::setupViews()
{
	//添加背景图片
	setBackImage("loading.png");

	CCSprite* pTitle = CCSprite::create("menuTitle.png", CCRectMake(0, 34, 133, 36));
	pTitle->setPosition(ccp(getSize().width/2, getSize().height/2 + 40));
	addChild(pTitle);

	//加入说明文字
	CCLabelBMFont* pDes = CCLabelBMFont::create("  This Game is developped by shenhuabin \n version is 1.0 \n QQ:510336806", "arial-14.fnt");
	pDes->setPosition(ccp(getSize().width/2, getSize().height/2));
	addChild(pDes);

	//添加返回按钮
	CCLabelBMFont* pBack = CCLabelBMFont::create("<--Go Back", "arial-14.fnt");
	CCMenuItemLabel* pItem = CCMenuItemLabel::create(pBack, this, menu_selector(AboutLayer::GoBack_Func));
	CCMenu* pMenu = CCMenu::create(pItem, NULL);
	pMenu->setPosition(ccp(getSize().width/2, getSize().height/2 - 150));
	addChild(pMenu);
}

void AboutLayer::GoBack_Func(CCObject* pSender)
{
	CCLOG("go back call back");
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, MainLayer::scene()));
}

