#pragma once

#include "Engine/Hackables/HackableObject.h"

namespace cocos2d
{
	class Sprite;
}

class CollisionObject;

class CatapultBall : public HackableObject
{
public:
	static CatapultBall* create(const cocos2d::ValueMap& properties, cocos2d::Vec2 velocity);

	static const std::string MapKeyCatapultBall;

protected:
	CatapultBall(const cocos2d::ValueMap& properties, cocos2d::Vec2 velocity);
	virtual ~CatapultBall();

	void onEnter() override;
	void initializePositions() override;
	void update(float) override;
	cocos2d::Vec2 getButtonOffset() override;
	void registerHackables() override;

private:
	typedef HackableObject super;

	bool isAccelerating;
	cocos2d::Sprite* ball;
	CollisionObject* ballCollision;
	cocos2d::Vec2 velocity;
};
