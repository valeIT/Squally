#include "Torch.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"

#include "Engine/Animations/SmartAnimationSequenceNode.h"
#include "Engine/Camera/GameCamera.h"
#include "Engine/Utils/GameUtils.h"

#include "Resources/FXResources.h"
#include "Resources/ObjectResources.h"

using namespace cocos2d;

const std::string Torch::MapKey = "torch";

Torch* Torch::create(ValueMap& properties)
{
	Torch* instance = new Torch(properties);

	instance->autorelease();

	return instance;
}

Torch::Torch(ValueMap& properties) : super(properties)
{
	this->torch = Sprite::create(ObjectResources::Decor_Torch_Torch);
	this->glow = Sprite::create(ObjectResources::Decor_Torch_TorchGlow);
	this->fire = SmartAnimationSequenceNode::create(FXResources::TorchFire_TorchFire_0000);
	this->isOn = false;
	this->isCulled = false;

	this->fire->setScale(1.5f);
	this->setContentSize(Size(128.0f, 128.0f));

	this->addChild(this->glow);
	this->addChild(this->torch);
	this->addChild(this->fire);
}

Torch::~Torch()
{
}

void Torch::onEnter()
{
	super::onEnter();

	this->torchOn();
	this->scheduleUpdate();
}

void Torch::update(float dt)
{
	super::update(dt);
	
	this->optimizationHideOffscreenTorch();
}

void Torch::initializePositions()
{
	super::initializePositions();

	this->fire->setPosition(Vec2(0.0f, 80.0f));
	this->glow->setPosition(Vec2(0.0f, 56.0f));
}

void Torch::torchOn()
{
	if (this->isOn)
	{
		return;
	}

	this->isOn = true;

	this->updateTorchVisibility();
}

void Torch::torchOff()
{
	if (!this->isOn)
	{
		return;
	}

	this->isOn = false;

	this->updateTorchVisibility();
}

void Torch::updateTorchVisibility()
{
	this->glow->stopAllActions();
	this->fire->stopAnimation();

	if (this->isOn && !this->isCulled)
	{
		this->fire->playAnimationRepeat(FXResources::TorchFire_TorchFire_0000, 0.05f);

		this->glow->runAction(RepeatForever::create(Sequence::create(
			FadeTo::create(1.0f, 0),
			DelayTime::create(0.25f),
			FadeTo::create(1.0f, 255),
			DelayTime::create(0.25f),
			nullptr
		)));
	}
}

void Torch::optimizationHideOffscreenTorch()
{
	static const Size Padding = Size(128.0f, 128.0f);
	static const Rect CameraRect = Rect(Vec2::ZERO, Director::getInstance()->getVisibleSize());
	Rect thisRect = GameUtils::getScreenBounds(this, Padding);

	bool isNotOnScreen = !CameraRect.intersectsRect(thisRect);

	if (this->isCulled != isNotOnScreen)
	{
		this->isCulled = isNotOnScreen;

		this->updateTorchVisibility();
	}
}
