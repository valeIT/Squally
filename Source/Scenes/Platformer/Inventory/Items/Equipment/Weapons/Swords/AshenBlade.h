#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Swords/Sword.h"

class AshenBlade : public Sword
{
public:
	static AshenBlade* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;
	Recipe* getRecipe() override;

	static const std::string SaveKey;

protected:
	AshenBlade();
	virtual ~AshenBlade();

private:
	typedef Sword super;
};
