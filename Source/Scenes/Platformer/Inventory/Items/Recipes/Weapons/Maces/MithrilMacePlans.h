#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Maces/MaceRecipe.h"

class MithrilMacePlans : public MaceRecipe
{
public:
	static MithrilMacePlans* create();

	std::vector<Item*> craft() override;
	Item* clone() override;
	const std::string& getItemName() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	std::string getCraftedItemIconResource() override;
	const std::string& getSerializationKey() override;

	static const std::string SaveKey;

protected:
	MithrilMacePlans();
	virtual ~MithrilMacePlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef MaceRecipe super;
};
