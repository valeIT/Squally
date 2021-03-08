#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Gear/Necklaces/Necklace.h"

class SapphireNecklace : public Necklace
{
public:
	static SapphireNecklace* create();

	Item* clone() override;
	const std::string& getItemName() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getSerializationKey() override;

	static const std::string SaveKey;

protected:
	SapphireNecklace();
	virtual ~SapphireNecklace();

private:
	typedef Necklace super;
};
