#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Swords/Sword.h"

class Dreadmourn : public Sword
{
public:
	static Dreadmourn* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;
	Recipe* getRecipe() override;

	static const std::string SaveKey;

protected:
	Dreadmourn();
	virtual ~Dreadmourn();

private:
	typedef Sword super;
};
