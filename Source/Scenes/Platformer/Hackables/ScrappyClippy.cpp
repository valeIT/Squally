#include "ScrappyClippy.h"

#include "cocos/2d/CCSprite.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/SpeechBubble.h"

#include "Resources/EntityResources.h"
#include "Resources/SoundResources.h"
#include "Scenes/Platformer/Dialogue/Voices.h"

#include "Strings/Strings.h"

using namespace cocos2d;

ScrappyClippy* ScrappyClippy::create(LocalizedString* helpText, std::string uniqueRunKey)
{
	ScrappyClippy* instance = new ScrappyClippy(helpText, uniqueRunKey);

	instance->autorelease();

	return instance;
}

ScrappyClippy::ScrappyClippy(LocalizedString* helpText, std::string uniqueRunKey) : super(uniqueRunKey)
{
	this->clippyAnimations = SmartAnimationNode::create(EntityResources::Helpers_EndianForest_Scrappy_Animations);
	this->helpText = helpText;

	this->clippyAnimations->setFlippedX(true);

	this->animationNode->addChild(this->clippyAnimations);
	this->addChild(helpText);
}

ScrappyClippy::~ScrappyClippy()
{
}

void ScrappyClippy::startDialogue()
{
	this->runDialogue(this->helpText == nullptr ? nullptr : this->helpText->clone(), Voices::GetNextVoiceMedium(Voices::VoiceType::Droid));
}
