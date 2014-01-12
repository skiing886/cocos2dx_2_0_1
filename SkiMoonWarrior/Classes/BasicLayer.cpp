#include "BasicLayer.h"

BasicLayer::BasicLayer()
{

}
BasicLayer::~BasicLayer()
{

}

// on "init" you need to initialize your instance
bool BasicLayer::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());

        bRet = true;
    } while (0);

    return bRet;
}

CCSize BasicLayer::getSize()
{
	return CCDirector::sharedDirector()->getWinSize();
}

void BasicLayer::setBackImage(const char* pImageName)
{
	CCSprite* pSp = CCSprite::create(pImageName);
//	CC_BREAK_IF(!pSp);
	pSp->setPosition(ccp(getSize().width/2, getSize().height/2));
	addChild(pSp);
}

