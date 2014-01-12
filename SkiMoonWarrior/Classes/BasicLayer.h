#ifndef __BASIC_LAYER_H__
#define __BASIC_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;


class BasicLayer : public CCLayer
{
public:
	BasicLayer();
	~BasicLayer();
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  


    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(BasicLayer);

public:
	CCSize getSize();
	void setBackImage(const char* pImageName);

};

#endif  // __HELLOWORLD_SCENE_H__