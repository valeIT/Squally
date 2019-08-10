#include "EntityMovementBehaviorBase.h"

#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Input/Input.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Save/SaveManager.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Scenes/Platformer/AttachedBehaviors/Entities/Collision/EntityGroundCollisionBehaviors.h"
#include "Scenes/Platformer/AttachedBehaviors/Entities/Collision/EntityMovementCollisionBehaviors.h"
#include "Scenes/Platformer/AttachedBehaviors/Entities/Stats/EntityHealthBehaviorBase.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Resources/EntityResources.h"

using namespace cocos2d;

const float EntityMovementBehaviorBase::MoveAcceleration = 5800.0f;
const Vec2 EntityMovementBehaviorBase::SwimAcceleration = Vec2(8000.0f, 420.0f);
const float EntityMovementBehaviorBase::JumpVelocity = 7680.0f;

EntityMovementBehaviorBase::EntityMovementBehaviorBase(GameObject* owner, std::string attachedBehaviorArgs) : super(owner, attachedBehaviorArgs)
{
	this->entity = static_cast<PlatformerEntity*>(owner);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}
}

EntityMovementBehaviorBase::~EntityMovementBehaviorBase()
{
	this->movement = Vec2::ZERO;
}

void EntityMovementBehaviorBase::update(float dt)
{
	super::update(dt);

	if (this->entity->isCinimaticHijacked || this->entity->getIsPlatformerDisabled())
	{
		return;
	}

	EntityMovementCollisionBehaviors* movementCollision = this->entity->getAttachedBehavior<EntityMovementCollisionBehaviors>();
	EntityHealthBehaviorBase* health = this->entity->getAttachedBehavior<EntityHealthBehaviorBase>();
	EntityGroundCollisionBehaviors* groundBehaviors = this->entity->getAttachedBehavior<EntityGroundCollisionBehaviors>();

	if (movementCollision == nullptr)
	{
		return;
	}

	if (health != nullptr && health->isDead())
	{
		this->movement = Vec2::ZERO;
	}

	Vec2 velocity = movementCollision->getVelocity();

	bool isOnGround = groundBehaviors == nullptr ? false : groundBehaviors->isOnGround();

	switch (this->entity->controlState)
	{
		default:
		case PlatformerEntity::ControlState::Normal:
		{
			// Move in the x direction unless hitting a wall while not standing on anything (this->entity prevents wall jumps)
			if ((this->movement.x < 0.0f && !movementCollision->hasLeftWallCollision()) ||
				(this->movement.x > 0.0f && !movementCollision->hasRightWallCollision()))
			{
				velocity.x += this->movement.x * EntityMovementBehaviorBase::MoveAcceleration * dt;
			}

			if (this->movement.y > 0.0f && isOnGround)
			{
				velocity.y = this->movement.y * EntityMovementBehaviorBase::JumpVelocity;

				this->entity->performJumpAnimation();
			}

			break;
		}
		case PlatformerEntity::ControlState::Swimming:
		{
			const float minSpeed = EntityMovementBehaviorBase::SwimAcceleration.y;

			// A lil patch to reduce that "acceleraton" feel of swimming vertical, and instead make it feel more instant
			if (velocity.y < minSpeed && this->movement.y > 0.0f)
			{
				velocity.y = minSpeed;
			}
			else if (velocity.y > -minSpeed && this->movement.y < 0.0f)
			{
				velocity.y = -minSpeed;
			}

			velocity.x += this->movement.x * EntityMovementBehaviorBase::SwimAcceleration.x * dt;
			velocity.y += this->movement.y * EntityMovementBehaviorBase::SwimAcceleration.y * dt;

			if (this->movement != Vec2::ZERO)
			{
				this->entity->performSwimAnimation();
			}

			break;
		}
	}
	
	// Save velocity
	movementCollision->setVelocity(velocity);

	this->entity->setState(StateKeys::VelocityX, Value(velocity.x));
	this->entity->setState(StateKeys::VelocityY, Value(velocity.y));

	// Update flip
	if (this->entity->animationNode != nullptr)
	{
		if (this->movement.x < 0.0f)
		{
			this->entity->animationNode->setFlippedX(true);
		}
		else if (this->movement.x > 0.0f)
		{
			this->entity->animationNode->setFlippedX(false);
		}
	}
}

void EntityMovementBehaviorBase::onLoad()
{
	this->scheduleUpdate();
}
