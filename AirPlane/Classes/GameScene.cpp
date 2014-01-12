#include "GameScene.h"

using namespace cocos2d;

GameScene::GameScene()
{
	_gameLayer = NULL;
}
GameScene::~GameScene()
{

}



// on "init" you need to initialize your instance
bool GameScene::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCScene::init());

		_gameLayer = GameLayer::create();//创建GameLayer对象
		CC_BREAK_IF(!_gameLayer);

       this->addChild(_gameLayer);

        bRet = true;
    } while (0);

    return bRet;
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

