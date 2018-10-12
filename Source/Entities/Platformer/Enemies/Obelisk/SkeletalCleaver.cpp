#include "SkeletalCleaver.h"

const std::string SkeletalCleaver::MapKeyEnemySkeletalCleaver = "skeletal_cleaver";

SkeletalCleaver* SkeletalCleaver::deserialize(ValueMap* initProperties)
{
	SkeletalCleaver* instance = new SkeletalCleaver(initProperties);

	instance->autorelease();

	return instance;
}

SkeletalCleaver::SkeletalCleaver(ValueMap* initProperties) : PlatformerEnemy(initProperties,
	Resources::Entities_Platformer_Environment_Obelisk_Enemies_SkeletalCleaver_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(128.0f, 312.0f),
	0.8f,
	Vec2(0.0f, 16.0f))
{
}

SkeletalCleaver::~SkeletalCleaver()
{
}
