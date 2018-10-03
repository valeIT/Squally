#pragma once
#include "cocos2d.h"

#include "Engine/Localization/Localization.h"
#include "Resources.h"
#include "Scenes/Hexus/Components/Banners/BannerBase.h"

using namespace cocos2d;

class VictoryBanner : public BannerBase
{
public:
	static VictoryBanner * create();

protected:
	void onStateChange(GameState* eventCustom) override;

private:
	VictoryBanner();
	~VictoryBanner();

	void initializePositions() override;
};