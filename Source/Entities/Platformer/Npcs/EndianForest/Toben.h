#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class LocalizedString;

class Toben : public PlatformerFriendly
{
public:
	static Toben* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;

protected:
	Toben(cocos2d::ValueMap& properties);
	virtual ~Toben();

private:
	typedef PlatformerFriendly super;
};
