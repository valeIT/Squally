#pragma once

#include "Scenes/Hexus/Menus//ChapterSelect/HexusChapterPreview.h"

class HexusChapterPreviewCastle : public HexusChapterPreview
{
public:
	static HexusChapterPreviewCastle* create();

	static const std::string SaveKeyChapterName;

protected:
	HexusChapterPreviewCastle();
	~HexusChapterPreviewCastle();

private:
	typedef HexusChapterPreview super;
	void initializePositions() override;
};