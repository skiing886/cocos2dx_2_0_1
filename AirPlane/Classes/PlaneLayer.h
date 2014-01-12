#ifndef __PLANE_LAYER_H__
#define __PLANE_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;

#define PLANE_TAG	1

#define GET_SPRITE_FRAME(XXX) CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(XXX))

class PlaneLayer : public cocos2d::CCLayer
{
public:
	PlaneLayer();
	~PlaneLayer();

	static PlaneLayer* create();//we implement it

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	
public:
	static PlaneLayer* sharePlane;//public data member 

};

#endif  