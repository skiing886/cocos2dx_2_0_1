#ifndef __SCORE_LAYER_H__
#define __SCORE_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "BasicLayer.h"

using namespace cocos2d;


class ScoreLayer : public BasicLayer
{
public:
	ScoreLayer(){}
	~ScoreLayer(){}
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(ScoreLayer);
public:
	void setupViews();

private:
	void bgScroll_Func(float fTime);
};

#endif  