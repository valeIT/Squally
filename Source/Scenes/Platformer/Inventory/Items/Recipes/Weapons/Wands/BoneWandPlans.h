#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Wands/WandRecipe.h"

class BoneWandPlans : public WandRecipe
{
public:
	static BoneWandPlans* create();

	std::vector<Item*> craft() override;
	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	std::string getCraftedItemIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	BoneWandPlans();
	virtual ~BoneWandPlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef WandRecipe super;
};
