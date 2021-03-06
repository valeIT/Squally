#pragma once

#include "Scenes/Platformer/Inventory/Items/Crafting/Crafting.h"

class LocalizedString;

class PhoenixFeather : public Crafting
{
public:
	static PhoenixFeather* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	PhoenixFeather();
	virtual ~PhoenixFeather();

private:
	typedef Crafting super;
};
