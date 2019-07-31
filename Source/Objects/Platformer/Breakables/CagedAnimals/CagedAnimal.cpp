#include "CagedAnimal.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"

#include "Engine/Animations/SmartAnimationSequenceNode.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Save/SaveManager.h"
#include "Engine/Sound/Sound.h"

#include "Scenes/Platformer/Level/Physics/PlatformerCollisionType.h"

#include "Resources/ObjectResources.h"
#include "Resources/FXResources.h"

using namespace cocos2d;

CagedAnimal::CagedAnimal(ValueMap& initProperties, std::string saveKey) : super(initProperties, 1)
{
	this->animalNode = Node::create();
	this->shineFx = Sprite::create(ObjectResources::Collectables_Animals_CollectShine);
	this->saveKey = saveKey;
	this->alreadyCollected = false;

	this->shineFx->setOpacity(0);

	this->animalNode->setScale(0.75f);

	this->animalNode->addChild(this->shineFx);
	this->contentNode->addChild(this->animalNode);
}

CagedAnimal::~CagedAnimal()
{
	ObjectEvents::TriggerUnbindObject(ObjectEvents::RelocateObjectArgs(this->animalNode));
}

void CagedAnimal::onEnter()
{
	super::onEnter();

	if (SaveManager::getProfileDataOrDefault(this->saveKey, Value(false)).asBool())
	{
		this->alreadyCollected = true;
		this->animalNode->setVisible(false);
		this->shineFx->setVisible(false);
	}
}

void CagedAnimal::initializePositions()
{
	super::initializePositions();

	this->animalNode->setPosition(Vec2(0.0f, 0.0f));
}

void CagedAnimal::initializeListeners()
{
	super::initializeListeners();
}

Vec2 CagedAnimal::getButtonOffset()
{
	return Vec2(0.0f, 96.0f);
}

void CagedAnimal::onBreak()
{
	super::onBreak();

	if (this->alreadyCollected)
	{
		return;
	}

	SaveManager::saveProfileData(this->saveKey, Value(true));

	ObjectEvents::TriggerMoveObjectToTopLayer(ObjectEvents::RelocateObjectArgs(this->animalNode));

	this->shineFx->runAction(Sequence::create(
		FadeTo::create(0.25f, 255),
		DelayTime::create(2.0f),
		FadeTo::create(0.25f, 0),
		nullptr
	));
	this->shineFx->runAction(Repeat::create(RotateBy::create(4.0f, 360.0f), 2));

	this->animalNode->runAction(Sequence::create(
		MoveBy::create(1.0f, Vec2(0.0f, 128.0f)),
		DelayTime::create(1.25f),
		FadeTo::create(0.25f, 0),
		nullptr
	));
}