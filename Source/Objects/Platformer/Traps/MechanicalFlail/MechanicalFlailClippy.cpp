#include "MechanicalFlailClippy.h"

#include "cocos/2d/CCSprite.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/SpeechBubble.h"
#include "Engine/Localization/LocalizedString.h"
#include "Engine/Sound/Sound.h"

#include "Resources/EntityResources.h"
#include "Resources/SoundResources.h"

#include "Strings/Menus/Hacking/ClippyHelp/MechanicalFlailMov.h"

using namespace cocos2d;

MechanicalFlailClippy* MechanicalFlailClippy::create()
{
	MechanicalFlailClippy* instance = new MechanicalFlailClippy();

	instance->autorelease();

	return instance;
}

MechanicalFlailClippy::MechanicalFlailClippy() : super()
{
	this->clippyAnimations = SmartAnimationNode::create(EntityResources::Helpers_EndianForest_Scrappy_Animations);

	this->clippyAnimations->setFlippedX(true);

	this->animationNode->addChild(this->clippyAnimations);
}

MechanicalFlailClippy::~MechanicalFlailClippy()
{
}

Clippy* MechanicalFlailClippy::innerClone()
{
	return MechanicalFlailClippy::create();
}

void MechanicalFlailClippy::onEnterTransitionDidFinish()
{
	super::onEnterTransitionDidFinish();

	this->speechBubble->runDialogue(Strings::Menus_Hacking_ClippyHelp_MechanicalFlailMov::create(), SoundResources::Platformer_Entities_Droid_DroidChatter, SpeechBubble::InfiniteDuration);
}
