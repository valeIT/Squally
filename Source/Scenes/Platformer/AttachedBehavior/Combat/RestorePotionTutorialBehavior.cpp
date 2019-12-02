#include "RestorePotionTutorialBehavior.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/SpeechBubble.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Events/HackableEvents.h"
#include "Engine/Inventory/Inventory.h"
#include "Engine/Inventory/Item.h"
#include "Engine/Sound/WorldSound.h"
#include "Engine/Utils/GameUtils.h"
#include "Entities/Platformer/Helpers/EndianForest/Scrappy.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Dialogue/EntityDialogueBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Items/EntityInventoryBehavior.h"
#include "Scenes/Platformer/Inventory/Items/Consumables/Health/RestorePotion/RestorePotion.h"
#include "Scenes/Platformer/Inventory/Items/Consumables/Health/RestorePotion/RestoreHealth.h"
#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttack.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Resources/SoundResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string RestorePotionTutorialBehavior::MapKeyAttachedBehavior = "restore-potion-tutorial";

RestorePotionTutorialBehavior* RestorePotionTutorialBehavior::create(GameObject* owner)
{
	RestorePotionTutorialBehavior* instance = new RestorePotionTutorialBehavior(owner);

	instance->autorelease();

	return instance;
}

RestorePotionTutorialBehavior::RestorePotionTutorialBehavior(GameObject* owner) : super(owner)
{
	this->entity = dynamic_cast<PlatformerEntity*>(owner);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}

	this->hasTutorialRun = false;
	this->scrappy = nullptr;
}

RestorePotionTutorialBehavior::~RestorePotionTutorialBehavior()
{
}

void RestorePotionTutorialBehavior::onLoad()
{
	this->entity->getAttachedBehavior<EntityInventoryBehavior>([=](EntityInventoryBehavior* entityInventoryBehavior)
	{
		RestorePotion* restorePotion = entityInventoryBehavior->getInventory()->getItemOfType<RestorePotion>();

		if (restorePotion != nullptr)
		{
			restorePotion->getAssociatedAttack()->registerAttackCompleteCallback([=]()
			{
				this->runTutorial();
			});
		}
	});

	ObjectEvents::watchForObject<Scrappy>(this, [=](Scrappy* scrappy)
	{
		this->scrappy = scrappy;
	}, Scrappy::MapKeyScrappy);

	HackableEvents::TriggerDisallowHackerMode();
}

void RestorePotionTutorialBehavior::runTutorial()
{
	if (this->hasTutorialRun || this->scrappy == nullptr)
	{
		return;
	}

	this->hasTutorialRun = true;

	static const float TutorialDelay = RestoreHealth::StartDelay + RestoreHealth::TimeBetweenTicks * 2.0f + 0.1f;

	this->runAction(Sequence::create(
		DelayTime::create(TutorialDelay),
		CallFunc::create([=]()
		{
			HackableEvents::TriggerAllowHackerMode();
			HackableEvents::TriggerForceHackerModeEnable();

			// Hackermode will pause scrappy and render the dialogue box inaccessible -- remedy this
			GameUtils::resume(this->scrappy);
			
			this->scrappy->getAttachedBehavior<EntityDialogueBehavior>([=](EntityDialogueBehavior* interactionBehavior)
			{
				interactionBehavior->getSpeechBubble()->runDialogue(Strings::Platformer_Quests_EndianForest_Intro_F_HackerModeCombat::create(), SoundResources::Platformer_Entities_Droid_DroidChatter, 4.0f);
			});
		}),
		nullptr
	));
}
