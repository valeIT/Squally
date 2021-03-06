#include "CandySwordPlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string CandySwordPlans::SaveKey = "candy-sword-plans";

CandySwordPlans* CandySwordPlans::create()
{
	CandySwordPlans* instance = new CandySwordPlans();

	instance->autorelease();

	return instance;
}

CandySwordPlans::CandySwordPlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

CandySwordPlans::~CandySwordPlans()
{
}

std::vector<Item*> CandySwordPlans::craft()
{
	return { CandySword::create() };
}

std::vector<std::tuple<Item*, int>> CandySwordPlans::getReagentsInternal()
{
	return
	{
		{ Wood::create(), 2 },
		{ Iron::create(), 4 },
	};
}

Item* CandySwordPlans::clone()
{
	return CandySwordPlans::create();
}

LocalizedString* CandySwordPlans::getString()
{
	return Strings::Items_Equipment_Weapons_Swords_CandySword::create();
}

const std::string& CandySwordPlans::getIconResource()
{
	return ItemResources::Misc_SCROLL_1;
}

std::string CandySwordPlans::getCraftedItemIconResource()
{
	return ItemResources::Equipment_Weapons_Special_CandySword;
}

const std::string& CandySwordPlans::getIdentifier()
{
	return CandySwordPlans::SaveKey;
}
