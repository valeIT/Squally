#pragma once
#include <functional>

#include "Engine/SmartNode.h"

// forward declarations
namespace cocos2d
{
	class Sprite;
}

class SmartAnimationSequenceNode : public SmartNode
{
public:
	static SmartAnimationSequenceNode* create(std::string defaultSprite);
	static SmartAnimationSequenceNode* create();

	void primeCache(std::string initialSequenceResourceFile);
	void playAnimation(std::string initialSequenceResourceFile, float animationSpeed, std::function<void()> onAnimationComplete = nullptr);
	void playAnimationRepeat(std::string initialSequenceResourceFile, float animationSpeed, float repeatDelay);
	void playAnimationAndReverse(std::string initialSequenceResourceFile, float animationSpeedIn, float reverseDelay, float animationSpeedOut, std::function<void()> onAnimationComplete = nullptr);
	void playAnimationAndReverseRepeat(std::string initialSequenceResourceFile, float animationSpeedIn, float reverseDelay, float animationSpeedOut, float repeatDelay, bool startReversed = false);

	void setFlippedX(bool isFlipped);
	void setFlippedY(bool isFlipped);

protected:
	cocos2d::Sprite* sprite;

private:
	SmartAnimationSequenceNode();
	SmartAnimationSequenceNode(std::string defaultSprite);
	virtual ~SmartAnimationSequenceNode();

	static std::map<std::string, std::vector<std::string>> AnimationFileCache;
	static std::vector<std::string> getAllAnimationFiles(std::string firstFrameResource);
};