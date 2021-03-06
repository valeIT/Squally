#pragma once

#include "Engine/Hackables/Menus/HackablePreview.h"

namespace cocos2d
{
	class Sprite;
}

class LocalizedLabel;

class HeavenHugSetSpeedPreview : public HackablePreview
{
public:
	static HeavenHugSetSpeedPreview* create();

	HackablePreview* clone() override;

protected:
	HeavenHugSetSpeedPreview();
	virtual ~HeavenHugSetSpeedPreview();

	void onEnter() override;
	void initializePositions() override;

private:
	typedef HackablePreview super;

	cocos2d::Sprite* previewHeavenHug100;
	cocos2d::Sprite* previewHeavenHug200;
	cocos2d::Sprite* previewHeavenHug400;
	LocalizedLabel* eax100Height;
	LocalizedLabel* eax200Height;
	LocalizedLabel* eax400Height;
};
