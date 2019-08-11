#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class Squally;

class SquallyEqBehavior : public AttachedBehavior
{
public:
	static SquallyEqBehavior* create(GameObject* owner, std::string attachedBehaviorArgs);

	static const std::string MapKeyAttachedBehavior;

protected:
	SquallyEqBehavior(GameObject* owner, std::string attachedBehaviorArgs);
	~SquallyEqBehavior();

	void onLoad() override;

private:
	typedef AttachedBehavior super;
	
	void saveState();

	Squally* squally;
};
