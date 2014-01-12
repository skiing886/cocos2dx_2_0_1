#include "GameLayer.h"
#include "MainLayer.h"
#include "TimeLayer.h"
#include "PauseLayer.h"

#include "Define.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
bool PauseLayer::init()
{
    bool bRet = false;
    do 
	{
		//为暂停层创建透明背景
        CC_BREAK_IF(! CCLayerColor::initWithColor(ccc4(0,0,0,50)));

		//默认创建的层的大小和屏幕大小一致
		setupViews();


        bRet = true;
    } while (0);

    return bRet;
}

void PauseLayer::setupViews()
{
	do
	{
		CCMenuItemImage* pResume = CCMenuItemImage::create("play.png", "play.png", 
															this, menu_selector(PauseLayer::resume_Func));
		CCMenu* pMenu = CCMenu::create(pResume, NULL);
		pMenu->setAnchorPoint(ccp(0, 0));
		pMenu->setPosition(getContentSize().width/2, getContentSize().height/2);
		addChild(pMenu);
	}
	while(0);
	
}

void PauseLayer::resume_Func(CCObject* pSender)
{
	setVisible(false);

	CCDirector::sharedDirector()->resume();

	if(!SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/mainMainMusic.mp3");
}