#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Gear/Hats/Hat.h"

class Monocle : public Hat
{
public:
	static Monocle* create();

	Item* clone() override;
	const std::string& getItemName() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;
	cocos2d::Vec2 getDisplayOffset() override;

	static const std::string SaveKey;

protected:
	Monocle();
	virtual ~Monocle();

private:
	typedef Hat super;
};
