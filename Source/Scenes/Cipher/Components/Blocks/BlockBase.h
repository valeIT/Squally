#pragma once

#include "Scenes/Cipher/Components/CipherComponentBase.h"

namespace cocos2d
{
	class Sprite;
}

class InputBolt;
class OutputBolt;
class ClickableNode;
class LocalizedLabel;
class LocalizedString;

class BlockBase : public CipherComponentBase
{
public:
	enum class BlockType
	{
		Toolbox,
		Normal,
		Static,
	};

	void removeConnections();

protected:
	enum class ConnectionType
	{
		None,
		Single,
		Double
	};

	BlockBase(BlockType blockType, ConnectionType inputType, ConnectionType outputType, ClickableNode* block, std::string iconResource, LocalizedString* label);
	~BlockBase();

	void initializePositions() override;
	void initializeListeners() override;
	virtual BlockBase* spawn() = 0;
	bool isInGameArea();

	ClickableNode* block;
	BlockType blockType;

private:
	typedef CipherComponentBase super;

	cocos2d::Sprite* icon;
	LocalizedLabel* label;
	std::vector<InputBolt*> inputBolts;
	std::vector<OutputBolt*> outputBolts;
	
	ConnectionType inputType;
	ConnectionType outputType;
	cocos2d::Vec2 originalPosition;
	cocos2d::Vec2 clickDelta;
};