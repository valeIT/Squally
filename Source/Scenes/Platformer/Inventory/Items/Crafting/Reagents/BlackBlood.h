#pragma once

#include "Scenes/Platformer/Inventory/Items/Crafting/Crafting.h"

class LocalizedString;

class BlackBlood : public Crafting
{
public:
	static BlackBlood* create();

	Item* clone() override;
	const std::string& getItemName() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getSerializationKey() override;

	static const std::string SaveKey;

protected:
	BlackBlood();
	virtual ~BlackBlood();

private:
	typedef Crafting super;
};
