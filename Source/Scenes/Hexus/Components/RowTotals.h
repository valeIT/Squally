#pragma once

#include "Scenes/Hexus/Components/ComponentBase.h"

namespace cocos2d
{
	class Sprite;
}

class LocalizedLabel;

class RowTotals : public ComponentBase
{
public:
	static RowTotals* create();

	// Public so that tutorials can focus these
	cocos2d::Sprite* enemyBinaryTotalSocket;
	cocos2d::Sprite* enemyDecimalTotalSocket;
	cocos2d::Sprite* enemyHexTotalSocket;
	cocos2d::Sprite* playerBinaryTotalSocket;
	cocos2d::Sprite* playerDecimalTotalSocket;
	cocos2d::Sprite* playerHexTotalSocket;

protected:
	void onBeforeStateChange(GameState* gameState) override;
	void onAnyStateChange(GameState* gameState) override;

private:
	typedef ComponentBase super;
	RowTotals();
	~RowTotals();

	void onEnter() override;
	void initializePositions() override;
	void readNewTotals(GameState* gameState, bool displayDeltas);
	void updateTotals(GameState* gameState);
	void runDeltaAnimation(LocalizedLabel* label, float startPositionY, int delta);

	LocalizedLabel* enemyBinaryCardTotal;
	LocalizedLabel* enemyDecimalCardTotal;
	LocalizedLabel* enemyHexCardTotal;
	LocalizedLabel* playerBinaryCardTotal;
	LocalizedLabel* playerDecimalCardTotal;
	LocalizedLabel* playerHexCardTotal;

	LocalizedLabel* enemyBinaryCardIncreaseLabel;
	LocalizedLabel* enemyDecimalCardIncreaseLabel;
	LocalizedLabel* enemyHexCardIncreaseLabel;
	LocalizedLabel* playerBinaryCardIncreaseLabel;
	LocalizedLabel* playerDecimalCardIncreaseLabel;
	LocalizedLabel* playerHexCardIncreaseLabel;

	LocalizedLabel* enemyBinaryCardDecreaseLabel;
	LocalizedLabel* enemyDecimalCardDecreaseLabel;
	LocalizedLabel* enemyHexCardDecreaseLabel;
	LocalizedLabel* playerBinaryCardDecreaseLabel;
	LocalizedLabel* playerDecimalCardDecreaseLabel;
	LocalizedLabel* playerHexCardDecreaseLabel;

	int cachedEnemyBinaryTotal;
	int cachedEnemyDecimalTotal;
	int cachedEnemyHexTotal;
	int cachedPlayerBinaryTotal;
	int cachedPlayerDecimalTotal;
	int cachedPlayerHexTotal;

	static const int CacheCipher;
};
