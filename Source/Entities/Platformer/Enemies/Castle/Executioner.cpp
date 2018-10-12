#include "Executioner.h"

const std::string Executioner::MapKeyEnemyExecutioner = "executioner";

Executioner* Executioner::deserialize(ValueMap* initProperties)
{
	Executioner* instance = new Executioner(initProperties);

	instance->autorelease();

	return instance;
}

Executioner::Executioner(ValueMap* initProperties) : PlatformerEnemy(initProperties,
	Resources::Entities_Platformer_Environment_Castle_Enemies_Executioner_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(472.0f, 820.0f),
	0.3f,
	Vec2(-24.0f, -410.0f))
{
}

Executioner::~Executioner()
{
}
