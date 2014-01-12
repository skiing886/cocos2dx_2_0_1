#ifndef __OPTION_LAYER_H__
#define __OPTION_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "BasicLayer.h"

using namespace cocos2d;


class OptionLayer : public BasicLayer
{
public:
	OptionLayer(){}
	~OptionLayer(){}
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static CCScene* scene();
    

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(OptionLayer);
public:
	void setupViews();

private:
	void GoBack_Func(CCObject* pSender);
	void Music_Func(CCObject* pSender);
};

#endif  