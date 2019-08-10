#include "EntityOutOfCombatAttackBehaviorBase.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Input/Input.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Save/SaveManager.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Scenes/Platformer/AttachedBehaviors/Entities/Collision/EntityWeaponCollisionBehaviors.h"
#include "Scenes/Platformer/Save/SaveKeys.h"

#include "Resources/UIResources.h"

using namespace cocos2d;

EntityOutOfCombatAttackBehaviorBase::EntityOutOfCombatAttackBehaviorBase(GameObject* owner, std::string attachedBehaviorArgs) : super(owner, attachedBehaviorArgs)
{
	this->entity = static_cast<PlatformerEntity*>(owner);
	this->outOfCombatAttackDebug = Sprite::create(UIResources::Menus_Icons_Swords);
	this->isPerformingOutOfCombatAttack = false;

	if (this->entity == nullptr)
	{
		this->invalidate();
	}
	
	this->addChild(this->outOfCombatAttackDebug);
}

EntityOutOfCombatAttackBehaviorBase::~EntityOutOfCombatAttackBehaviorBase()
{
}

void EntityOutOfCombatAttackBehaviorBase::initializePositions()
{
	super::initializePositions();

	this->outOfCombatAttackDebug->setPosition(Vec2(0.0f, this->entity->getEntitySize().height + this->entity->hoverHeight / 2.0f + 64.0f));
}


void EntityOutOfCombatAttackBehaviorBase::onDeveloperModeEnable()
{
	super::onDeveloperModeEnable();
}

void EntityOutOfCombatAttackBehaviorBase::onDeveloperModeDisable()
{
	super::onDeveloperModeDisable();

	this->outOfCombatAttackDebug->setVisible(false);
}

void EntityOutOfCombatAttackBehaviorBase::onLoad()
{
}

void EntityOutOfCombatAttackBehaviorBase::doOutOfCombatAttack(std::string attackAnimation, float onset, float sustain)
{
	if (this->isPerformingOutOfCombatAttack)
	{
		return;
	}

	this->isPerformingOutOfCombatAttack = true;
	this->entity->animationNode->playAnimation(attackAnimation);
	EntityWeaponCollisionBehaviors* weaponBehavior = this->entity->getAttachedBehavior<EntityWeaponCollisionBehaviors>();

	this->runAction(Sequence::create(
		DelayTime::create(onset),
		CallFunc::create([=]()
		{
			if (this->isDeveloperModeEnabled())
			{
				this->outOfCombatAttackDebug->setVisible(true);
			}

			weaponBehavior->enable();
		}),
		DelayTime::create(sustain),
		CallFunc::create([=]()
		{
			weaponBehavior->disable();
			this->isPerformingOutOfCombatAttack = false;
			this->outOfCombatAttackDebug->setVisible(false);
		}),
		nullptr
	));
}