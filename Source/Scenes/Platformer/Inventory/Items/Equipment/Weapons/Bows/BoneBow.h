#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Bows/Bow.h"

class BoneBow : public Bow
{
public:
	static BoneBow* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;
	cocos2d::Vec2 getDisplayOffset() override;
	Recipe* getRecipe() override;

	static const std::string SaveKey;

protected:
	BoneBow();
	virtual ~BoneBow();

private:
	typedef Bow super;
};
