#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Maces/MaceRecipe.h"

class WitchingMacePlans : public MaceRecipe
{
public:
	static WitchingMacePlans* create();

	std::vector<Item*> craft() override;
	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	std::string getCraftedItemIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	WitchingMacePlans();
	virtual ~WitchingMacePlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef MaceRecipe super;
};
