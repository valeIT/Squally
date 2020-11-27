#include "SpikedLogSetRotationPreview.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"

#include "Engine/Animations/SmartAnimationSequenceNode.h"
#include "Engine/Localization/ConstantString.h"
#include "Engine/Localization/LocalizedLabel.h"
#include "Engine/Utils/MathUtils.h"

#include "Resources/ObjectResources.h"

using namespace cocos2d;

SpikedLogSetRotationPreview* SpikedLogSetRotationPreview::create()
{
	SpikedLogSetRotationPreview* instance = new SpikedLogSetRotationPreview();

	instance->autorelease();

	return instance;
}

SpikedLogSetRotationPreview::SpikedLogSetRotationPreview()
{
	this->previewSpikedLog = SmartAnimationSequenceNode::create(ObjectResources::Traps_SpikedLog_SpikedLog_00);

	this->previewSpikedLog->setScale(0.4f);

	this->countString = ConstantString::create("0");

	this->ecxAnimationCount = this->createRegisterEqualsValueLabel(HackableCode::Register::zcx, false, this->countString);

	this->previewNode->addChild(this->previewSpikedLog);
	this->assemblyTextNode->addChild(this->ecxAnimationCount);
}

SpikedLogSetRotationPreview::~SpikedLogSetRotationPreview()
{
}

HackablePreview* SpikedLogSetRotationPreview::clone()
{
	return SpikedLogSetRotationPreview::create();
}

void SpikedLogSetRotationPreview::onEnter()
{
	super::onEnter();

	this->previewSpikedLog->setPosition(Vec2(0.0f, 0.0f));
	this->previewSpikedLog->playAnimationRepeat(ObjectResources::Traps_SpikedLog_SpikedLog_00, 0.5f, 0.0f);

	/*
	this->previewSpikedLog->getForwardsAnimation()->incrementCallback = [=](int count, int max)
	{
		count = MathUtils::wrappingNormalize(count + 1, 0, max);

		this->countString->setString(std::to_string(count));

		return count;
	};
	*/
}

void SpikedLogSetRotationPreview::initializePositions()
{
	super::initializePositions();

	this->ecxAnimationCount->setPosition(Vec2(0.0f, HackablePreview::PreviewRadius - 64.0f));
}
