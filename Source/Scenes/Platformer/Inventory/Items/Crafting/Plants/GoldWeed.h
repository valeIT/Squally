#pragma once

#include "Scenes/Platformer/Inventory/Items/Crafting/Crafting.h"

class LocalizedString;

class GoldWeed : public Crafting
{
public:
	static GoldWeed* create();

	Item* clone() override;
	const std::string& getItemName() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getSerializationKey() override;

	static const std::string SaveKey;

protected:
	GoldWeed();
	virtual ~GoldWeed();

private:
	typedef Crafting super;
};
