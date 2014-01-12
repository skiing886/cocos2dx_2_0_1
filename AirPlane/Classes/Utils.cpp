#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Utils.h"

using namespace cocos2d;

int Utils::Random(int nMode = 0)
{
	static int bInit = false;
	if(!bInit)
	{
		srand(time(NULL));
		bInit = true;
	}
	return nMode==0?rand():rand()%nMode;
}



