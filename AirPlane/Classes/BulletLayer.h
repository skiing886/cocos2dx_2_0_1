#ifndef __BULLET_LAYER_H__
#define __BULLET_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;

class BulletLayer : public cocos2d::CCLayer
{
public:
	BulletLayer();
	~BulletLayer();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	LAYER_CREATE_FUNC(BulletLayer);

public:
	void AddBullet(float dt);
	void DeleteBullet(CCNode* pSender);
	void RemoveBullet(CCSprite* pBullet);

	void StartShoot(float fDelay);
	void StopShoot();
	
private:
	CCSpriteBatchNode* m_pBatchNode ;
	CCArray* m_pAllBullet;

};

#endif  