#ifndef __TIME_LAYER_H__
#define __TIME_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "BasicLayer.h"

using namespace cocos2d;


class TimeLayer : public BasicLayer
{
public:
	TimeLayer():m_nCounter(0){}
	~TimeLayer(){}
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(TimeLayer);
public:
	void setupViews();

private:
	void tmWaste_Func(float fTime);

private:
	int m_nCounter;
};

#endif  