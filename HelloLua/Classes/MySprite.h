#ifndef __MY_SPRITE_H__
#define __MY_SPRITE_H__

#include "cocos2d.h"

using namespace cocos2d;

class MySprite : public CCSprite
{
public:
	static MySprite* createMySprite();
	void initMy();
};




#endif
