#include "GameLayer.h"
#include "MainLayer.h"
#include "ScoreLayer.h"

#include "Define.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
bool ScoreLayer::init()
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

void ScoreLayer::setupViews()
{
	do
	{
		CCLabelBMFont* pFnt = CCLabelBMFont::create("Score : 0", "arial-14.fnt");
		pFnt->setAnchorPoint(CCPointZero);
		pFnt->setPosition(ccp(0, 0));
		pFnt->setScale(1.5);
		addChild(pFnt);
	}
	while(0);
	
}