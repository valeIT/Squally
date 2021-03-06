#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class LocalizedString;

class PenguinGrunt : public PlatformerEnemy
{
public:
	static PenguinGrunt* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;
	
protected:
	PenguinGrunt(cocos2d::ValueMap& properties);
	virtual ~PenguinGrunt();

private:
	typedef PlatformerEnemy super;
};
