#pragma once

#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/CardData/CardData.h"

using namespace cocos2d;

class CardBinary5 : public CardData
{
public:
	CardBinary5();
	~CardBinary5();

private:
	static const std::string StringKeyCardName;
};