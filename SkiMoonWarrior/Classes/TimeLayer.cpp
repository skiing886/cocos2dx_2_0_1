#include "GameLayer.h"
#include "MainLayer.h"
#include "TimeLayer.h"

#include "Define.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
bool TimeLayer::init()
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

void TimeLayer::setupViews()
{
	do
	{
		CCLabelBMFont* pFnt = CCLabelBMFont::create("Time : 0s", "arial-14.fnt");
		pFnt->setAnchorPoint(CCPointZero);
		pFnt->setPosition(ccp(0, 0));
		pFnt->setScale(1.5);
		addChild(pFnt, 0, TIME_BM_FONT_TAG);

		schedule(schedule_selector(TimeLayer::tmWaste_Func), 1.0f);
	}
	while(0);
	
}

void TimeLayer::tmWaste_Func(float fTime)
{
	++m_nCounter;
	char szStr[56] = {0};
	sprintf(szStr, "Time : %ds", m_nCounter);

	CCLabelBMFont* pFnt = (CCLabelBMFont*)getChildByTag(TIME_BM_FONT_TAG);
	pFnt->setString(szStr);
}