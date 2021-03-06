#pragma once

#include "Scenes/Platformer/Inventory/Items/Collectables/HexusCards/HexusCard.h"

class LocalizedString;

class SpecialAbsorb : public HexusCard
{
public:
	static SpecialAbsorb* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;
	std::string getCardKey() override;

	static const std::string SaveKey;

protected:
	SpecialAbsorb();
	virtual ~SpecialAbsorb();

private:
	typedef HexusCard super;
};
