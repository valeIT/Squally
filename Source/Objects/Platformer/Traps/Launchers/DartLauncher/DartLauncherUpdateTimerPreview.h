#pragma once

#include "Engine/Hackables/Menus/HackablePreview.h"

namespace cocos2d
{
	class Sprite;
}

class ConstantFloat;
class LocalizedLabel;

class DartLauncherUpdateTimerPreview : public HackablePreview
{
public:
	static DartLauncherUpdateTimerPreview* create();

	HackablePreview* clone() override;

private:
	typedef HackablePreview super;

	DartLauncherUpdateTimerPreview();
	~DartLauncherUpdateTimerPreview();
	void onEnter() override;
	void initializePositions() override;
	void update(float dt) override;

	bool isLaunching;
	float launchCountDown;

	cocos2d::Sprite* dartLauncher;
	cocos2d::Sprite* dart;
	ConstantFloat* eaxTimerStr;
	LocalizedLabel* eaxTimer;
};
