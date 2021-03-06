#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class LocalizedString;

class Elriel : public PlatformerFriendly
{
public:
	static Elriel* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;

protected:
	Elriel(cocos2d::ValueMap& properties);
	virtual ~Elriel();

private:
	typedef PlatformerFriendly super;
};
