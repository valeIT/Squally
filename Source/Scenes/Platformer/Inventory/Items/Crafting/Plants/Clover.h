#pragma once

#include "Scenes/Platformer/Inventory/Items/Crafting/Crafting.h"

class LocalizedString;

class Clover : public Crafting
{
public:
	static Clover* create();

	Item* clone() override;
	const std::string& getItemName() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getSerializationKey() override;

	static const std::string SaveKey;

protected:
	Clover();
	virtual ~Clover();

private:
	typedef Crafting super;
};
