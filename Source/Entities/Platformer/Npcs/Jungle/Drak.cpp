#include "Drak.h"

const std::string Drak::MapKeyNpcDrak = "drak";

Drak* Drak::deserialize(ValueMap* initProperties)
{
	Drak* instance = new Drak(initProperties);

	instance->autorelease();

	return instance;
}

Drak::Drak(ValueMap* initProperties) : NpcBase(initProperties,
	Resources::Entities_Platformer_Environment_Jungle_Npcs_Drak_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Drak::~Drak()
{
}