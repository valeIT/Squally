#include "HexusOpponentDemonGrunt.h"

const std::string HexusOpponentDemonGrunt::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_DEMON_GRUNT";
HexusOpponentDemonGrunt* HexusOpponentDemonGrunt::instance = nullptr;

HexusOpponentDemonGrunt* HexusOpponentDemonGrunt::getInstance()
{
	if (HexusOpponentDemonGrunt::instance == nullptr)
	{
		HexusOpponentDemonGrunt::instance = new HexusOpponentDemonGrunt();
	}

	return HexusOpponentDemonGrunt::instance;
}

HexusOpponentDemonGrunt::HexusOpponentDemonGrunt() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Volcano_Enemies_DemonGrunt_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameVolcano,
	0.85f,
	Vec2(-48.0f, -48.0f),
	Vec2(-32.0f, -64.0f),
	HexusOpponentDemonGrunt::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.765f,
		{
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalOr),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalXor),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		})
	)
{
}

HexusOpponentDemonGrunt::~HexusOpponentDemonGrunt()
{
}