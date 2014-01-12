#ifndef __PAUSE_LAYER_H__
#define __PAUSE_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "BasicLayer.h"

using namespace cocos2d;


class PauseLayer : public CCLayerColor
{
public:
	PauseLayer(){}
	~PauseLayer(){}
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(PauseLayer);
public:
	void setupViews();

private:
	void resume_Func(CCObject* pSender);

};

#endif  