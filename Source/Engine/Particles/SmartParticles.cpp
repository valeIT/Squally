#include "SmartParticles.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCDrawNode.h"
#include "cocos/2d/CCParticleSystemQuad.h"
#include "cocos/base/CCDirector.h"

#include "Engine/Camera/GameCamera.h"
#include "Engine/Utils/GameUtils.h"

using namespace cocos2d;

SmartParticles* SmartParticles::create(std::string particleResource, CullInfo cullInfo)
{
	SmartParticles* instance = new SmartParticles(particleResource, cullInfo);

	instance->autorelease();

	return instance;
}

SmartParticles::SmartParticles(std::string particleResource, CullInfo cullInfo) : super()
{
	this->particles = ParticleSystemQuad::create(particleResource);
	this->debugDrawNode = DrawNode::create();
	this->cullInfo = cullInfo;

	this->boundsRect = Rect(Vec2::ZERO, this->cullInfo.size);

	this->stop();

	if (cullInfo.cull)
	{
		this->debugDrawNode->drawRect(-Vec2(this->cullInfo.size) / 2.0f, Vec2(this->cullInfo.size) / 2.0f, Color4F::GREEN);
	}

	this->addChild(this->debugDrawNode);
	this->addChild(this->particles);
}

SmartParticles::~SmartParticles()
{ 
}

void SmartParticles::onEnter()
{
	super::onEnter();
	
	if (this->cullInfo.cull)
	{
		this->optimizationHideOffscreenParticles();
		this->scheduleUpdate();
	}
}

void SmartParticles::onDeveloperModeEnable(int debugLevel)
{
	if (debugLevel >= 2)
	{
		this->debugDrawNode->setVisible(true);
	}
}

void SmartParticles::onDeveloperModeDisable()
{
	this->debugDrawNode->setVisible(false);
}

void SmartParticles::update(float dt)
{
	super::update(dt);
	
	this->optimizationHideOffscreenParticles();
}

ParticleSystem* SmartParticles::getParticles()
{
	return this->particles;
}

void SmartParticles::start()
{
	if (this->particles == nullptr)
	{
		return;
	}
	
	this->stopAllActions();
	this->particles->start();
	this->particles->toggleCanUpdate(true);
	this->particles->resumeEmissions();
	this->particles->setVisible(true);
}

void SmartParticles::restart()
{
	if (this->particles == nullptr)
	{
		return;
	}
	
	this->particles->resetSystem();
}

void SmartParticles::stop(float disableUpdateAfter)
{
	if (this->particles == nullptr)
	{
		return;
	}

	this->particles->stopSystem();
	this->particles->pauseEmissions();

	if (disableUpdateAfter <= 0.0f)
	{
		this->particles->toggleCanUpdate(false);
		this->particles->setVisible(false);
	}
	else
	{
		this->runAction(Sequence::create(
			DelayTime::create(disableUpdateAfter),
			CallFunc::create([=]()
			{
				this->particles->toggleCanUpdate(false);
				this->particles->setVisible(false);
			}),
			nullptr
		));
	}
}

bool SmartParticles::isActive()
{
	if (this->particles == nullptr)
	{
		return false;
	}

	return this->particles->isActive();
}

void SmartParticles::accelerate(float duration)
{
	if (this->particles == nullptr)
	{
		return;
	}

	const float step = 1.0f / 60.0f;

	this->start();

	for (float currentDuration = 0.0f; currentDuration < duration; currentDuration += step)
	{
		this->particles->update(step);
	}
}

void SmartParticles::setGrouped()
{
	if (this->particles == nullptr)
	{
		return;
	}

	this->particles->setPositionType(ParticleSystem::PositionType::GROUPED);
}

void SmartParticles::setRelative()
{
	if (this->particles == nullptr)
	{
		return;
	}

	this->particles->setPositionType(ParticleSystem::PositionType::RELATIVE);
}

void SmartParticles::setFree()
{
	if (this->particles == nullptr)
	{
		return;
	}

	this->particles->setPositionType(ParticleSystem::PositionType::FREE);
}

void SmartParticles::optimizationHideOffscreenParticles()
{
	if (!this->cullInfo.cull)
	{
		return;
	}

	float zoom = GameCamera::getInstance()->getCameraZoomOnTarget(this);
	static const Size Padding = Size(512.0f, 512.0f);
	Size clipSize = (Director::getInstance()->getVisibleSize() + Padding) * zoom;
	Rect cameraRect = Rect(GameCamera::getInstance()->getCameraPosition() - Vec2(clipSize.width / 2.0f, clipSize.height / 2.0f), clipSize);
	Rect thisRect = this->boundsRect;

	thisRect.origin += GameUtils::getWorldCoords(this);

	if (cameraRect.intersectsRect(thisRect))
	{
		this->particles->setVisible(true);
	}
	else
	{
		this->particles->setVisible(false);
	}
}
