#include "PlatformerEntity.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/physics/CCPhysicsWorld.h"

#include "Engine/Animations/AnimationPart.h"
#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/SpeechBubble.h"
#include "Engine/Hackables/HackablePreview.h"
#include "Engine/Input/ClickableNode.h"
#include "Engine/Inventory/CurrencyInventory.h"
#include "Engine/Inventory/Inventory.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Physics/EngineCollisionTypes.h"
#include "Engine/Utils/GameUtils.h"
#include "Engine/Utils/MathUtils.h"
#include "Events/PlatformerEvents.h"
#include "Entities/Platformer/EntityPreview.h"
#include "Entities/Platformer/StatsTables/StatsTables.h"
#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttack.h"
#include "Scenes/Platformer/Inventory/EquipmentInventory.h"

#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string PlatformerEntity::MapKeyPropertyState = "state";

PlatformerEntity::PlatformerEntity(
	ValueMap& properties, 
	std::string scmlResource,
	std::string emblemResource,
	PlatformerCollisionType collisionType,
	Size size,
	float scale, 
	Vec2 collisionOffset,
	float hoverHeight,
	std::string inventorySaveKey,
	std::string equipmentSaveKey,
	std::string currencySaveKey
	) : super(properties)
{
	this->animationNode = SmartAnimationNode::create(scmlResource);
	this->entityScale = scale;
	this->collisionType = collisionType;
	this->animationResource = scmlResource;
	this->emblemResource = emblemResource;
	this->isCinimaticHijacked = false;
	this->isPlatformerDisabled = false;
	this->entityName = GameUtils::getKeyOrDefault(this->properties, GameObject::MapKeyName, Value("")).asString();
	this->state = GameUtils::getKeyOrDefault(this->properties, PlatformerEntity::MapKeyPropertyState, Value("")).asString();
	this->entityCollisionOffset = this->entityScale * collisionOffset;
	
	this->entitySize = size * scale;
	
	this->entityCollision = CollisionObject::create(
		CollisionObject::createCapsulePolygon(size, scale * 0.9f, 8.0f),
		(CollisionType)(int)this->collisionType,
		false,
		false
	);

	this->hexusOpponentData = nullptr;
	this->inventory = Inventory::create(inventorySaveKey);
	this->equipmentInventory = EquipmentInventory::create(equipmentSaveKey);
	this->currencyInventory = CurrencyInventory::create(currencySaveKey);
	this->speechBubble = SpeechBubble::create();
	this->attacks = std::vector<PlatformerAttack*>();
	this->spawnCoords = this->getPosition();
	this->hoverHeight = hoverHeight;
	this->controlState = ControlState::Normal;
	this->movementSize = this->entitySize * this->entityScale + Size(0.0f, this->hoverHeight);

	this->hackButtonOffset = Vec2(this->entityCollisionOffset.x, this->entityCollisionOffset.y + this->hoverHeight + this->entitySize.height);

	this->animationNode->setScale(scale);
	this->animationNode->playAnimation("Idle");
	this->animationNode->setPositionY(this->hoverHeight / 2.0f);
	
	this->animationNode->setAnchorPoint(Vec2(0.5f, 0.0f));
	this->setAnchorPoint(Vec2(0.5f, 0.0f));

	this->animationNode->setFlippedX(GameUtils::getKeyOrDefault(this->properties, PlatformerEntity::MapKeyFlipX, Value(false)).asBool());
	this->animationNode->setFlippedY(GameUtils::getKeyOrDefault(this->properties, PlatformerEntity::MapKeyFlipY, Value(false)).asBool());

	this->addChild(this->entityCollision);
	this->addChild(this->animationNode);
	this->addChild(this->speechBubble);
	this->addChild(this->inventory);
	this->addChild(this->equipmentInventory);
	this->addChild(this->currencyInventory);
}

PlatformerEntity::~PlatformerEntity()
{
}

void PlatformerEntity::onEnter()
{
	super::onEnter();

	this->scheduleUpdate();
}

void PlatformerEntity::initializePositions()
{
	super::initializePositions();

	this->speechBubble->setPositionY(this->entitySize.height / 2.0f + 16.0f);
}

void PlatformerEntity::initializeListeners()
{
	super::initializeListeners();

	this->addEventListener(EventListenerCustom::create(PlatformerEvents::EventCinematicHijack, [=](EventCustom*)
	{
		this->isCinimaticHijacked = true;
	}));

	this->addEventListener(EventListenerCustom::create(PlatformerEvents::EventCinematicRestore, [=](EventCustom*)
	{
		this->isCinimaticHijacked = false;
	}));
}

Vec2 PlatformerEntity::getButtonOffset()
{
	return this->hackButtonOffset;
}

HackablePreview* PlatformerEntity::createDefaultPreview()
{
	return EntityPreview::create(this);
}

std::string PlatformerEntity::getEntityName()
{
	return this->entityName;
}

float PlatformerEntity::getFloatHeight()
{
	return 0.0f;
}

void PlatformerEntity::performSwimAnimation()
{
	this->animationNode->playAnimation("Swim");
}

void PlatformerEntity::performJumpAnimation()
{
	this->animationNode->playAnimation("Jump");
}

bool PlatformerEntity::getIsPlatformerDisabled()
{
	return this->isPlatformerDisabled;
}

void PlatformerEntity::disablePlatformerControls()
{
	this->isPlatformerDisabled = true;
}

SmartAnimationNode* PlatformerEntity::getAnimations()
{
	return this->animationNode;
}

Size PlatformerEntity::getEntitySize()
{
	return this->entitySize;
}

HexusOpponentData* PlatformerEntity::getHexusOpponentData()
{
	return this->hexusOpponentData;
}

std::vector<PlatformerAttack*> PlatformerEntity::getAttacks()
{
	return this->attacks;
}

std::vector<PlatformerAttack*> PlatformerEntity::getAvailableAttacks()
{
	std::vector<PlatformerAttack*> availableAttacks = std::vector<PlatformerAttack*>();

	for (auto it = this->attacks.begin(); it != this->attacks.end(); it++)
	{
		/* TODO: Broken until attacks abstracted into their own behavior
		if ((*it)->getSpecialCost() <= this->getMana())
		{
			availableAttacks.push_back(*it);
		}*/
	}

	return availableAttacks;
}

std::vector<PlatformerAttack*> PlatformerEntity::cloneAttacks()
{
	std::vector<PlatformerAttack*> attacksClone = std::vector<PlatformerAttack*>();

	for (auto it = this->attacks.begin(); it != this->attacks.end(); it++)
	{
		attacksClone.push_back((*it)->clone());
	}

	return attacksClone;
}

Inventory* PlatformerEntity::getInventory()
{
	return this->inventory;
}

EquipmentInventory* PlatformerEntity::getEquipmentInventory()
{
	return this->equipmentInventory;
}

CurrencyInventory* PlatformerEntity::getCurrencyInventory()
{
	return this->currencyInventory;
}

void PlatformerEntity::registerAttack(PlatformerAttack* attack)
{
	this->addChild(attack);
	this->attacks.push_back(attack);
}

float PlatformerEntity::getScale()
{
	return this->entityScale;
}

std::string PlatformerEntity::getAnimationResource()
{
	return this->animationResource;
}

std::string PlatformerEntity::getEmblemResource()
{
	return this->emblemResource;
}
