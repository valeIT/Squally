#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Gear/Hats/Hat.h"

class WizardsHat : public Hat
{
public:
	static WizardsHat* create();

	Item* clone() override;
	const std::string& getItemName() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getSerializationKey() override;
	cocos2d::Vec2 getDisplayOffset() override;

	static const std::string SaveKey;

protected:
	WizardsHat();
	virtual ~WizardsHat();

private:
	typedef Hat super;
};
