#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Maces/Mace.h"

class WitchingMace : public Mace
{
public:
	static WitchingMace* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;
	cocos2d::Vec2 getDisplayOffset() override;
	Recipe* getRecipe() override;

	static const std::string SaveKey;

protected:
	WitchingMace();
	virtual ~WitchingMace();

private:
	typedef Mace super;
};
