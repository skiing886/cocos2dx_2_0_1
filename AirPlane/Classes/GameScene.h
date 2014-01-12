#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "GameLayer.h"

using namespace cocos2d;


class GameScene : public cocos2d::CCScene
{
public:
	GameScene();
	~GameScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    //static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    SCENE_CREATE_FUNC(GameScene);

	GameLayer* _gameLayer;//����GameLayer��ָ��
};

#endif  // __HELLOWORLD_SCENE_H__