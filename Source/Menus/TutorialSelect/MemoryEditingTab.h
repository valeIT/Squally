#pragma once

#include "Menus/TutorialSelect/TutorialTabBase.h"

namespace cocos2d
{
	class Sprite;
}

class ClickableTextNode;
class LocalizedLabel;
class PlatformerEntity;
class ScrollPane;
class TutorialEntry;

class MemoryEditingTab : public TutorialTabBase
{
public:
	static MemoryEditingTab* create();

protected:
	MemoryEditingTab();
	virtual ~MemoryEditingTab();

	void onEnter() override;
	void initializeListeners() override;
	void initializePositions() override;

private:
	typedef TutorialTabBase super;

	void loadKnownValueIntTutorial();
	void loadKnownValueFloatTutorial();
	void loadUnknownValueIntTutorial();
	void loadUnknownValueFloatTutorial();
	void loadKnownValueDoubleTutorial();
	void loadUnknownValueFloatTutorialAdvanced();

	TutorialEntry* knownValueInt;
	TutorialEntry* knownValueFloat;
	TutorialEntry* unknownValueInt;
	TutorialEntry* unknownValueFloat;
	TutorialEntry* knownValueDouble;
	TutorialEntry* unknownValueFloatAdvanced;
	
	PlatformerEntity* kingZul;
	PlatformerEntity* agnes;
	PlatformerEntity* lazarus;
	PlatformerEntity* asmodeus;
	PlatformerEntity* cryogen;
	PlatformerEntity* krampus;
};
