#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class ClickableNode;
class PlatformerEntity;

class EntitySelectionBehavior : public AttachedBehavior
{
public:
	static EntitySelectionBehavior* create(GameObject* owner);
	
	void setEntityClickCallbacks(std::function<void()> onClick, std::function<void()> onMouseOver = nullptr, std::function<void()> onMouseOut = nullptr);
	void setClickModifier(cocos2d::InputEvents::KeyCode modifier);
	void clearEntityClickCallbacks();
	ClickableNode* getHitbox();
	PlatformerEntity* getEntity();

	static const std::string MapKey;

protected:
	EntitySelectionBehavior(GameObject* owner);
	virtual ~EntitySelectionBehavior();
	
	void update(float dt) override;
	void onLoad() override;
	void onDisable() override;

private:
	typedef AttachedBehavior super;

	PlatformerEntity* entity;

	cocos2d::Vec3 savedWorldCoords;
	
	ClickableNode* clickHitbox;
};
