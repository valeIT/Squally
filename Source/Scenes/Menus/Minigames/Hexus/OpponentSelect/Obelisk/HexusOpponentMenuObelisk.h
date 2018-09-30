#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponents.h"
#include "Scenes/Menus/Minigames/Hexus/ChapterSelect/Obelisk/HexusChapterPreviewObelisk.h"
#include "Scenes/Menus/Minigames/Hexus/OpponentSelect/HexusOpponentMenuBase.h"
#include "Scenes/Menus/Minigames/Hexus/OpponentSelect/HexusOpponentPreview.h"

using namespace cocos2d;

class HexusOpponentMenuObelisk : public HexusOpponentMenuBase
{
public:
	static HexusOpponentMenuObelisk * create();

protected:
	HexusOpponentMenuObelisk();
	~HexusOpponentMenuObelisk();
};
