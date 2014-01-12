#include "SLog.h"

void SLog::Log(const char* pLog)
{
#ifdef DEBUG
		CCLOG("Log==>%s", pLog);
#endif	
}