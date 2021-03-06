#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Gear/Rings/Ring.h"

class ShellBand : public Ring
{
public:
	static ShellBand* create();

	Item* clone() override;
	LocalizedString* getString() override;
	const std::string& getIconResource() override;
	const std::string& getIdentifier() override;

	static const std::string SaveKey;

protected:
	ShellBand();
	virtual ~ShellBand();

private:
	typedef Ring super;
};
