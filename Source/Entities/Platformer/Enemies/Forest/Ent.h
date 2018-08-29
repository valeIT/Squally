#pragma once
#include "cocos2d.h"

#include "Entities/Platformer/PlatformerEnemy.h"
#include "Resources.h"

using namespace cocos2d;

class Ent : public PlatformerEnemy
{
public:
	static Ent * deserialize(ValueMap* initProperties);

	static const std::string KeyEnemyEnt;

private:
	Ent(ValueMap* initProperties);
	~Ent();
};