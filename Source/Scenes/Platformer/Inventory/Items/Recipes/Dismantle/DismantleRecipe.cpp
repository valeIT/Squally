#include "DismantleRecipe.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string DismantleRecipe::ItemNamePrefix = "dismantle-recipe-";

DismantleRecipe* DismantleRecipe::create(Item* item)
{
	DismantleRecipe* instance = new DismantleRecipe(item);

	instance->autorelease();

	return instance;
}

DismantleRecipe::DismantleRecipe(Item* item) : super()
{
	this->dismantleItem = item == nullptr ? nullptr : item->clone();
	this->dismantledItemRecipe = this->dismantleItem == nullptr ? nullptr : this->dismantleItem->getRecipe();
	this->dismantleItemName = DismantleRecipe::ItemNamePrefix + (this->dismantleItem == nullptr ? "" : this->dismantleItem->getItemName());

	if (this->dismantleItem != nullptr)
	{
		this->addChild(this->dismantleItem);
	}

	if (this->dismantledItemRecipe != nullptr)
	{
		this->addChild(this->dismantledItemRecipe);
	}
}

DismantleRecipe::~DismantleRecipe()
{
}

std::vector<Item*> DismantleRecipe::craft()
{
	std::vector<Item*> items = std::vector<Item*>();

	if (this->dismantledItemRecipe != nullptr)
	{
		std::vector<std::tuple<Item*, int>> reagents = this->dismantledItemRecipe->getReagents();

		for (const std::tuple<Item*, int>& reagent : reagents)
		{
			Item* item = std::get<0>(reagent);
			int count = std::get<1>(reagent);

			if (item == nullptr)
			{
				continue;
			}

			for (int index = 0; index < (count + 1) / 2; index++)
			{
				items.push_back(item->clone());
			}
		}
	}

	return items;
}

std::vector<std::tuple<Item*, int>> DismantleRecipe::getReagentsInternal()
{
	if (this->dismantleItem == nullptr)
	{
		return
		{
			{ MissingNo::create(), 1 }
		};
	}

	return
	{
		{ this->dismantleItem->clone(), 1 }
	};
}

Item* DismantleRecipe::clone()
{
	return DismantleRecipe::create(this->dismantleItem);
}

const std::string& DismantleRecipe::getItemName()
{
	return dismantleItemName;
}

LocalizedString* DismantleRecipe::getString()
{
	return this->dismantleItem == nullptr ? nullptr : this->dismantleItem->getString();
}

const std::string& DismantleRecipe::getIconResource()
{
	return this->dismantleItem == nullptr ? ItemResources::Misc_SCROLL_1 : this->dismantleItem->getIconResource();
}

std::string DismantleRecipe::getCraftedItemIconResource()
{
	return this->dismantledItemRecipe == nullptr ? ItemResources::Misc_SCROLL_1 : this->dismantledItemRecipe->getCraftedItemIconResource();
}

const std::string& DismantleRecipe::getSerializationKey()
{
	return DismantleRecipe::ItemNamePrefix;
}
