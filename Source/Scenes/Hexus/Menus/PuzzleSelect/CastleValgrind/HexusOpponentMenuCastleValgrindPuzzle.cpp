////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "HexusOpponentMenuCastleValgrindPuzzle.h"

#include "Engine/GlobalDirector.h"
#include "Engine/UI/Controls/ScrollPane.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Agnes.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Jack.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Reaper.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Scarecrow.h"
#include "Entities/Platformer/Enemies/CastleValgrind/SkeletalPirate.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Thug.h"
#include "Entities/Platformer/Enemies/CastleValgrind/VampireLord.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Vampiress.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Werewolf.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Wraith.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Zombie.h"
#include "Entities/Platformer/Enemies/CastleValgrind/ZombieElric.h"
#include "Scenes/Hexus/Menus/OpponentSelect/HexusOpponentPreview.h"
#include "Scenes/Hexus/Menus/ChapterSelect/CastleValgrind/HexusChapterPreviewCastleValgrindPuzzle.h"

using namespace cocos2d;

HexusOpponentMenuCastleValgrindPuzzle* HexusOpponentMenuCastleValgrindPuzzle::instance = nullptr;

void HexusOpponentMenuCastleValgrindPuzzle::registerGlobalScene()
{
	if (HexusOpponentMenuCastleValgrindPuzzle::instance == nullptr)
	{
		HexusOpponentMenuCastleValgrindPuzzle::instance = new HexusOpponentMenuCastleValgrindPuzzle();

		HexusOpponentMenuCastleValgrindPuzzle::instance->autorelease();
		HexusOpponentMenuCastleValgrindPuzzle::instance->initializeListeners();
	}

	GlobalDirector::registerGlobalScene(HexusOpponentMenuCastleValgrindPuzzle::instance);
}

HexusOpponentMenuCastleValgrindPuzzle::HexusOpponentMenuCastleValgrindPuzzle() : super(NavigationEvents::NavigateHexusOpponentSelectArgs::Chapter::PuzzleCastleValgrind, HexusChapterPreviewCastleValgrindPuzzle::SaveKeyChapterName)
{
	this->opponents.push_back(HexusOpponentPreview::create(Agnes::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(Jack::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(Reaper::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(Scarecrow::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(SkeletalPirate::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(Thug::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(VampireLord::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(Vampiress::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(Werewolf::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(Wraith::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(Zombie::getHexusOpponentData()));
	this->opponents.push_back(HexusOpponentPreview::create(ZombieElric::getHexusOpponentData()));

	this->buildOpponentList();
}

HexusOpponentMenuCastleValgrindPuzzle::~HexusOpponentMenuCastleValgrindPuzzle()
{
}