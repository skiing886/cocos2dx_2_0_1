#include "OptionLayer.h"
#include "MainLayer.h"

using namespace cocos2d;

CCScene* OptionLayer::scene()
{
    CCScene * pSc = NULL;
    do 
    {
        // 'scene' is an autorelease object
        pSc = CCScene::create();
        CC_BREAK_IF(! pSc);

        // 'layer' is an autorelease object
        OptionLayer *pLayer = OptionLayer::create();
        CC_BREAK_IF(! pLayer);

        // add layer as a child to scene
        pSc->addChild(pLayer);
    } while (0);

    // return the scene
    return pSc;
}

// on "init" you need to initialize your instance
bool OptionLayer::init()
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

void OptionLayer::setupViews()
{
	//Ìí¼Ó±³¾°Í¼Æ¬
	setBackImage("loading.png");

	CCSprite* pTitle = CCSprite::create("menuTitle.png", CCRectMake(0, 0, 133, 36));
	pTitle->setPosition(ccp(getSize().width/2, getSize().height/2 + 40));
	addChild(pTitle);

	CCMenuItemToggle* pItem = CCMenuItemToggle::create(this, menu_selector(OptionLayer::Music_Func), 
														CCMenuItemFont::create("Music : On"),
														CCMenuItemFont::create("Music : Off"),
														NULL);
	CCMenu* pMenu = CCMenu::create(pItem, NULL);
	pMenu->setPosition(ccp(getSize().width/2, getSize().height/2-20));
	addChild(pMenu);

	if(SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
		pItem->setSelectedIndex(1);
	else
		pItem->setSelectedIndex(0);

	//Ìí¼Ó·µ»Ø°´Å¥
	CCLabelBMFont* pFnt = CCLabelBMFont::create("<--Go Back", "arial-14.fnt");
	CCMenuItemLabel* pLabel = CCMenuItemLabel::create(pFnt, this, menu_selector(OptionLayer::GoBack_Func));
	CCMenu* pMenuBack = CCMenu::create(pLabel, NULL);
	pMenuBack->setPosition(ccp(getSize().width/2, getSize().height/2 - 150));
	addChild(pMenuBack);
	
}

void OptionLayer::GoBack_Func(CCObject* pSender)
{
	CCLOG("go back call back");
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, MainLayer::scene()));
}

void OptionLayer::Music_Func(CCObject* pSender)
{
	bool bPlaying = SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying();
	if(bPlaying)
	{
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		CCUserDefault::sharedUserDefault()->setBoolForKey("music_not_play", true);
	}
	else
	{
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/mainMainMusic.mp3");
		CCUserDefault::sharedUserDefault()->setBoolForKey("music_not_play", false);
	}
}

