#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponents.h"
#include "Scenes/Menus/Minigames/Hexus/ChapterSelect/HexusOpponentMenuBase.h"
#include "Scenes/Menus/Minigames/Hexus/ChapterSelect/HexusOpponentPreview.h"

using namespace cocos2d;

class HexusOpponentMenuRuins : public HexusOpponentMenuBase
{
public:
	static HexusOpponentMenuRuins * create();

protected:
	HexusOpponentMenuRuins();
	~HexusOpponentMenuRuins();
};

