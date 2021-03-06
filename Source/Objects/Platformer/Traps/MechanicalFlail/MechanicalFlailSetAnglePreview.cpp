#include "MechanicalFlailSetAnglePreview.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"

#include "Engine/Localization/ConstantString.h"
#include "Engine/Localization/LocalizedLabel.h"

#include "Resources/ObjectResources.h"


using namespace cocos2d;

MechanicalFlailSetAnglePreview* MechanicalFlailSetAnglePreview::create()
{
	MechanicalFlailSetAnglePreview* instance = new MechanicalFlailSetAnglePreview();

	instance->autorelease();

	return instance;
}

MechanicalFlailSetAnglePreview::MechanicalFlailSetAnglePreview()
{
	this->previewFlail = Sprite::create(ObjectResources::Traps_MechanicalFlail_PreviewFlail);
	this->previewJoint = Sprite::create(ObjectResources::Traps_MechanicalFlail_PreviewJoint);

	this->eax0Degrees = this->createRegisterEqualsValueLabel(HackableCode::Register::zbx, false, ConstantString::create("0"));
	this->eax90Degrees = this->createRegisterEqualsValueLabel(HackableCode::Register::zbx, false, ConstantString::create("90"));
	this->eax180Degrees = this->createRegisterEqualsValueLabel(HackableCode::Register::zbx, false, ConstantString::create("180"));
	this->eax270Degrees = this->createRegisterEqualsValueLabel(HackableCode::Register::zbx, false, ConstantString::create("270"));

	this->previewFlail->setAnchorPoint(Vec2(0.5f, 0.0f));

	this->previewNode->addChild(this->previewFlail);
	this->previewNode->addChild(this->previewJoint);
	this->assemblyTextNode->addChild(this->eax0Degrees);
	this->assemblyTextNode->addChild(this->eax90Degrees);
	this->assemblyTextNode->addChild(this->eax180Degrees);
	this->assemblyTextNode->addChild(this->eax270Degrees);
}

MechanicalFlailSetAnglePreview::~MechanicalFlailSetAnglePreview()
{
}

HackablePreview* MechanicalFlailSetAnglePreview::clone()
{
	return MechanicalFlailSetAnglePreview::create();
}

void MechanicalFlailSetAnglePreview::onEnter()
{
	super::onEnter();

	this->previewFlail->setRotation(0.0f);

	this->previewFlail->runAction(
		RepeatForever::create(Sequence::create(
			EaseSineInOut::create(RotateTo::create(1.5f, 270.0f)),
			EaseSineInOut::create(RotateTo::create(1.5f, 180.0f)),
			EaseSineInOut::create(RotateTo::create(1.5f, 90.0f)),
			EaseSineInOut::create(RotateTo::create(1.5f, 0.0f)),
			nullptr
		))
	);
}

void MechanicalFlailSetAnglePreview::initializePositions()
{
	super::initializePositions();

	const float offset = 24.0f;

	this->eax0Degrees->setPosition(Vec2(HackablePreview::PreviewRadius - offset, 0.0f));
	this->eax90Degrees->setPosition(Vec2(0.0f, HackablePreview::PreviewRadius - offset));
	this->eax180Degrees->setPosition(Vec2(-(HackablePreview::PreviewRadius - offset), 0.0f));
	this->eax270Degrees->setPosition(Vec2(0.0f, -(HackablePreview::PreviewRadius - offset)));
}
