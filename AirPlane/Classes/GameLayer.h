#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "PlaneLayer.h"
#include "BulletLayer.h"

using namespace cocos2d;

class GameLayer : public cocos2d::CCLayer
{
public:
	GameLayer();
	~GameLayer();
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void bkgMove(float dt);

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(GameLayer);

private:
	CCSprite* bkg1;
	CCSprite* bkg2;

private:
	PlaneLayer* pPlaneLayer;
	BulletLayer* pBulletLayer;

	

};

#endif  // __HELLOWORLD_SCENE_H__