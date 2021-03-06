#pragma once

#include "Engine/SmartNode.h"

namespace cocos2d
{
	class Node;
}

class ToggleCard;
class CardData;
class LocalizedLabel;

class BinDecHexHelpMenu : public SmartNode
{
public:
	static BinDecHexHelpMenu* create();

	void open(CardData* cardData);

protected:
	BinDecHexHelpMenu();
	virtual ~BinDecHexHelpMenu();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;

private:
	typedef SmartNode super;

	LocalizedLabel* description;
	ToggleCard* binCard;
	ToggleCard* decCard;
	ToggleCard* hexCard;
	LocalizedLabel* equalsLabelLeft;
	LocalizedLabel* equalsLabelRight;
	LocalizedLabel* binHeader;
	LocalizedLabel* decHeader;
	LocalizedLabel* hexHeader;
};
