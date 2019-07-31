#pragma once

#include "Objects/Platformer/Breakables/BreakableBase.h"

namespace cocos2d
{
	class Sprite;
}

class CollisionObject;
class SmartAnimationSequenceNode;
class Sound;

class BreakableBarrel : public BreakableBase
{
public:
	static BreakableBarrel* create(cocos2d::ValueMap& initProperties);

	static const std::string MapKeyBreakableBarrel;

protected:
	BreakableBarrel(cocos2d::ValueMap& initProperties);
	virtual ~BreakableBarrel();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void onBreak() override;

private:
	typedef BreakableBase super;

	cocos2d::Sprite* barrelSprite;
	Sound* breakSound;
	SmartAnimationSequenceNode* explosion;
};