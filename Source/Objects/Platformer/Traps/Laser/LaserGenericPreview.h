#pragma once

#include "Engine/Hackables/HackablePreview.h"

namespace cocos2d
{
	class Sprite;
}

class SmartAnimationSequenceNode;

class LaserGenericPreview : public HackablePreview
{
public:
	static LaserGenericPreview* create();

	HackablePreview* clone() override;

private:
	typedef HackablePreview super;

	LaserGenericPreview();
	~LaserGenericPreview() = default;
	void onEnter() override;
	void initializePositions() override;

	SmartAnimationSequenceNode* previewSpikes;
};
