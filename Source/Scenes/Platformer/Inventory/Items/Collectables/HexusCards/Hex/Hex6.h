#pragma once

#include "Scenes/Platformer/Inventory/Items/Collectables/HexusCards/HexusCard.h"

class LocalizedString;

class Hex6 : public HexusCard
{
public:
	static Hex6* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;
	std::string getCardKey() override;

	static const std::string SaveKey;

protected:
	Hex6();
	virtual ~Hex6();

private:
	typedef HexusCard super;
};
