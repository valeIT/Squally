#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class LocalizedString;

class KingRedsong : public PlatformerFriendly
{
public:
	static KingRedsong* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;

protected:
	KingRedsong(cocos2d::ValueMap& properties);
	virtual ~KingRedsong();

private:
	typedef PlatformerFriendly super;
};
