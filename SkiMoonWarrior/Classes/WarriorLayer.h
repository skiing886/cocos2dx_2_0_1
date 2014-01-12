#ifndef __WARRIOR_LAYER_H__
#define __WARRIOR_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "BasicLayer.h"

using namespace cocos2d;


class WarriorLayer : public BasicLayer
{
public:
	WarriorLayer(){}
	~WarriorLayer(){}
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(WarriorLayer);
public:
	void setupViews();
	CCPoint getWarriorPosition();

private:
	void tmWaste_Func(float fTime);
	// default implements are used to call script callback if exist
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	/** If isTouchEnabled, this method is called onEnter. Override it to change the
    way CCLayer receives touch events.
    ( Default: CCTouchDispatcher::sharedDispatcher()->addStandardDelegate(this,0); )
    Example:
    void CCLayer::registerWithTouchDispatcher()
    {
    CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this,INT_MIN+1,true);
    }
    @since v0.8.0
    */
    virtual void registerWithTouchDispatcher(void);

private:
	CCSprite* m_pWarrior;
};

#endif  