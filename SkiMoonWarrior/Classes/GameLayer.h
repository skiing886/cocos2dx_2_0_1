#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "BasicLayer.h"
#include "WarriorBulletManager.h"
#include "WarriorLayer.h"

using namespace cocos2d;


class GameLayer : public BasicLayer
{
public:
	GameLayer(){}
	~GameLayer(){}
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static CCScene* scene();
    

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(GameLayer);
public:
	void setupViews();

private:
	void bgScroll_Func(float fTime);
	void pause_Func(CCObject* pSender);
	void warriorFire_Func(float t);

private:
	WarriorLayer* m_pWarrior;
	WarriorBulletManager* m_pBulletMgr;
};

#endif  