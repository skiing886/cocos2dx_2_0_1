#include "MySprite.h"

MySprite* MySprite::createMySprite()
{
	MySprite* sp = new MySprite();
	if(!sp)
	{
		CC_SAFE_DELETE(sp);
		return NULL;
	}
	sp->initMy();
	sp->autorelease();//add the obj to the auto release pool

	return sp;
}
void MySprite::initMy()
{
	CCMessageBox("Hello, i am skiing", "test");
}