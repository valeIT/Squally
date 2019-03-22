#include "ShlBlock.h"

#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"

#include "Engine/Input/ClickableNode.h"
#include "Scenes/Cipher/Config.h"

#include "Resources/CipherResources.h"

#include "Strings/Cipher/Operations/SHL.h"

using namespace cocos2d;

ShlBlock* ShlBlock::create(BlockType blockType)
{
	ShlBlock* instance = new ShlBlock(blockType);

	instance->autorelease();

	return instance;
}

ShlBlock::ShlBlock(BlockType blockType) : super(blockType, ConnectionType::Double, ConnectionType::Single, ClickableNode::create(CipherResources::Blocks_BlockBin, CipherResources::Blocks_BlockBin), CipherResources::Icons_ShiftLeft, Strings::Cipher_Operations_SHL::create())
{
}

ShlBlock::~ShlBlock()
{
}

void ShlBlock::onEnter()
{
	super::onEnter();
}

void ShlBlock::initializePositions()
{
	super::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();
}

BlockBase* ShlBlock::spawn()
{
	return ShlBlock::create();
}