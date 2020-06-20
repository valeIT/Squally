#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class LocalizedString;

class Medusa : public PlatformerEnemy
{
public:
	static Medusa* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;
	
protected:
	Medusa(cocos2d::ValueMap& properties);
	virtual ~Medusa();

private:
	typedef PlatformerEnemy super;
};
