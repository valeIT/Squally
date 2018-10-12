#pragma once
#include "cocos2d.h"

#include "Entities/Platformer/PlatformerEnemy.h"
#include "Resources.h"

using namespace cocos2d;

class Abomination : public PlatformerEnemy
{
public:
	static Abomination * deserialize(ValueMap* initProperties);

	static const std::string MapKeyEnemyAbomination;

private:
	Abomination(ValueMap* initProperties);
	~Abomination();
};
