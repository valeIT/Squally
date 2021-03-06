#pragma once

#include "Scenes/Platformer/Inventory/Items/Crafting/Crafting.h"

class LocalizedString;

class Mandrake : public Crafting
{
public:
	static Mandrake* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	Mandrake();
	virtual ~Mandrake();

private:
	typedef Crafting super;
};
