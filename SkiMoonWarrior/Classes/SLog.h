#ifndef __SLOG_H__
#define __SLOG_H__

#include "cocos2d.h"

using namespace cocos2d;

#define DEBUG

class SLog
{
public:
	SLog(){}
	~SLog(){}
public:
	static void Log(const char* pLog);	
};

#endif  