#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class Squally;

class SquallyHudTrackBehavior : public AttachedBehavior
{
public:
	static SquallyHudTrackBehavior* create(GameObject* owner);

	static const std::string MapKey;

protected:
	SquallyHudTrackBehavior(GameObject* owner);
	virtual ~SquallyHudTrackBehavior();

	void onLoad() override;
	void onDisable() override;

private:
	typedef AttachedBehavior super;

	Squally* squally;
};
