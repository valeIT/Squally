#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Axes/AxeRecipe.h"

class WoodenAxePlans : public AxeRecipe
{
public:
	static WoodenAxePlans* create();

	std::vector<Item*> craft() override;
	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	std::string getCraftedItemIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	WoodenAxePlans();
	virtual ~WoodenAxePlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef AxeRecipe super;
};
