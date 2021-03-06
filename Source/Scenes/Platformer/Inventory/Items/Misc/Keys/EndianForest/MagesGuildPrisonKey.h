#pragma once

#include "Scenes/Platformer/Inventory/Items/Misc/Keys/Key.h"

class MagesGuildPrisonKey : public Key
{
public:
	static MagesGuildPrisonKey* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	MagesGuildPrisonKey();
	virtual ~MagesGuildPrisonKey();

private:
	typedef Key super;
};
