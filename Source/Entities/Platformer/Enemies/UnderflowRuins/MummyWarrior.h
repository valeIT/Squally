#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class LocalizedString;

class MummyWarrior : public PlatformerEnemy
{
public:
	static MummyWarrior* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;
	
protected:
	MummyWarrior(cocos2d::ValueMap& properties);
	virtual ~MummyWarrior();

private:
	typedef PlatformerEnemy super;
};
