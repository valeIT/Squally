#pragma once

#include "Scenes/Platformer/Inventory/Items/Crafting/Crafting.h"

class LocalizedString;

class DemonRoot : public Crafting
{
public:
	static DemonRoot* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	DemonRoot();
	virtual ~DemonRoot();

private:
	typedef Crafting super;
};
