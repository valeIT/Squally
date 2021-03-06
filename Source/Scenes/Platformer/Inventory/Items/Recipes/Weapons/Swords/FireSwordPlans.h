#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Swords/SwordRecipe.h"

class FireSwordPlans : public SwordRecipe
{
public:
	static FireSwordPlans* create();

	std::vector<Item*> craft() override;
	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	std::string getCraftedItemIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	FireSwordPlans();
	virtual ~FireSwordPlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef SwordRecipe super;
};
