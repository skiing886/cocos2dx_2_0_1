#ifndef __WARRIOR_BULLET_MANAGER_H__
#define __WARRIOR_BULLET_MANAGER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;


class WarriorBulletManager : public BasicLayer
{
public:
	WarriorBulletManager(){}
	~WarriorBulletManager(){}
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(WarriorBulletManager);
public:
	void setupViews();
	void addNewBullet(CCPoint ptStart);
	void moveAllBullets(float t);

private:


private:
	CCSpriteBatchNode* m_pBatchNode;
	CCArray* m_arrBullet;

};

#endif  