#pragma once

#include "Scenes/Platformer/Inventory/Items/Crafting/Crafting.h"

class LocalizedString;

class Obsidian : public Crafting
{
public:
	static Obsidian* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	Obsidian();
	virtual ~Obsidian();

private:
	typedef Crafting super;
};
