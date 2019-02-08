////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "TigerMan.h"

#include "Resources/EntityResources.h"

const std::string TigerMan::MapKeyTigerMan = "tiger-man";

TigerMan* TigerMan::deserialize(cocos2d::ValueMap& initProperties)
{
	TigerMan* instance = new TigerMan(initProperties);

	instance->autorelease();

	return instance;
}

TigerMan::TigerMan(cocos2d::ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_UnderflowRuins_TigerMan_Animations,
	EntityResources::Enemies_UnderflowRuins_TigerMan_Emblem,
	PlatformerCollisionType::Enemy,
	cocos2d::Size(256.0f, 308.0f),
	0.9f,
	cocos2d::Vec2(0.0f, 0.0f),
	10,
	10)
{
}

TigerMan::~TigerMan()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////
