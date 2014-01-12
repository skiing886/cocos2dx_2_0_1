#ifndef __UTILS_H__
#define __UTILS_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;

#define GET_SPRITE_FRAME(XXX) CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(XXX))

class Utils
{
public:
	static int Random();
	static int Random(int nMod);

};

#endif  