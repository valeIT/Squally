#include "ComponentBase.h"

#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Events/HexusEvents.h"
#include "Scenes/Hexus/GameState.h"

using namespace cocos2d;

ComponentBase::ComponentBase()
{
}

ComponentBase::~ComponentBase()
{
}

void ComponentBase::initializeListeners()
{
	super::initializeListeners();

	this->addEventListener(EventListenerCustom::create(HexusEvents::BeforeRequestStateUpdateEvent, [=](EventCustom* eventCustom)
	{
		this->onBeforeAnyRequestStateChange((GameState*)(eventCustom->getUserData()));
	}));
	this->addEventListener(EventListenerCustom::create(HexusEvents::RequestStateUpdateEvent, [=](EventCustom* eventCustom)
	{
		this->onAnyRequestStateChange((GameState*)(eventCustom->getUserData()));
	}));
	this->addEventListener(EventListenerCustom::create(HexusEvents::BeforeStateUpdateEvent, [=](EventCustom* eventCustom)
	{
		this->onBeforeStateChange((GameState*)(eventCustom->getUserData()));
	}));
	this->addEventListener(EventListenerCustom::create(HexusEvents::OnStateUpdateEvent, [=](EventCustom* eventCustom)
	{
		this->onAnyStateChange((GameState*)(eventCustom->getUserData()));
	}));
}

void ComponentBase::onBeforeStateChange(GameState* gameState)
{
}

void ComponentBase::onBeforeAnyRequestStateChange(GameState* gameState)
{
}

void ComponentBase::onAnyRequestStateChange(GameState* gameState)
{
}

void ComponentBase::onAnyStateChange(GameState* gameState)
{
}
