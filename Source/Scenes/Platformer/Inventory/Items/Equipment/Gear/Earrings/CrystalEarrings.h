#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Gear/Earrings/Earring.h"

class CrystalEarrings : public Earring
{
public:
	static CrystalEarrings* create();

	Item* clone() override;
	const std::string& getItemName() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getSerializationKey() override;

	static const std::string SaveKey;

protected:
	CrystalEarrings();
	virtual ~CrystalEarrings();

private:
	typedef Earring super;
};
