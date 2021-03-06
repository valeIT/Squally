#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class LocalizedString;

class GoblinElf : public PlatformerEnemy
{
public:
	static GoblinElf* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;
	
protected:
	GoblinElf(cocos2d::ValueMap& properties);
	virtual ~GoblinElf();

private:
	typedef PlatformerEnemy super;
};
