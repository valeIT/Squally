#pragma once
#include <functional>
#include <string>

#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventDispatcher.h"
#include "cocos/base/CCValue.h"

class UIBoundObject;
class MapLayer;
class GameObject;
class SmartNode;

class QueryObjectsArgsBase
{
public:
	virtual void tryInvoke(SmartNode* object) = 0;
};

template<class T>
class QueryObjectsArgs : QueryObjectsArgsBase
{
public:
	std::function<void(T*)> onObjectQueriedCallback;
	std::function<void(T*, bool*)> onObjectQueriedCallbackWithHandled;
	bool isHandled;

	QueryObjectsArgs(std::function<void(T*)> onObjectQueriedCallback) : onObjectQueriedCallback(onObjectQueriedCallback), onObjectQueriedCallbackWithHandled(nullptr), isHandled(false)
	{
	}

	QueryObjectsArgs(std::function<void(T*, bool*)> onObjectQueriedCallbackWithHandled) : onObjectQueriedCallback(nullptr), onObjectQueriedCallbackWithHandled(onObjectQueriedCallbackWithHandled), isHandled(false)
	{
	}

	void tryInvoke(SmartNode* object) override
	{
		if (dynamic_cast<T*>(object) != nullptr)
		{
			if (onObjectQueriedCallback != nullptr)
			{
				this->onObjectQueriedCallback((T*)object);
			}
			else if (onObjectQueriedCallbackWithHandled != nullptr && !this->isHandled)
			{
				this->onObjectQueriedCallbackWithHandled((T*)object, &this->isHandled);
			}
		}
	}
};

class ObjectEvents
{
public:
	static const std::string EventCollisonMapUpdated;
	static const std::string EventQueryObject;
	static const std::string EventBroadCastMapObjectStatePrefix;
	static const std::string EventSpawnObject;
	static const std::string EventSpawnObjectDelegator;
	static const std::string EventMoveObjectToTopLayer;
	static const std::string EventElevateObject;
	static const std::string EventUnbindObject;
	static const std::string EventWriteStatePrefix;

	enum class SpawnMethod
	{
		Below,
		Above,
	};

	enum class PositionMode
	{
		Discard,
		Retain,
		SetToOwner,
	};

	struct RequestObjectSpawnArgs
	{
		cocos2d::Node* spawner;
		cocos2d::Node* objectToSpawn;
		SpawnMethod spawnMethod;
		PositionMode positionMode;

		RequestObjectSpawnArgs() : spawner(nullptr), objectToSpawn(nullptr), spawnMethod(SpawnMethod::Above) { }
		RequestObjectSpawnArgs(cocos2d::Node* spawner, cocos2d::Node* objectToSpawn, SpawnMethod spawnMethod, PositionMode positionMode) : spawner(spawner), objectToSpawn(objectToSpawn), spawnMethod(spawnMethod), positionMode(positionMode) { }
	};

	struct RequestObjectSpawnDelegatorArgs
	{
		MapLayer* sourceLayer;
		cocos2d::Node* spawner;
		cocos2d::Node* objectToSpawn;
		SpawnMethod spawnMethod;
		PositionMode positionMode;

		RequestObjectSpawnDelegatorArgs() : sourceLayer(nullptr), spawner(nullptr), objectToSpawn(nullptr), spawnMethod(SpawnMethod::Above) { }
		RequestObjectSpawnDelegatorArgs(MapLayer* sourceLayer, cocos2d::Node* spawner, cocos2d::Node* objectToSpawn, SpawnMethod spawnMethod, PositionMode positionMode) : sourceLayer(sourceLayer), spawner(spawner), objectToSpawn(objectToSpawn), spawnMethod(spawnMethod), positionMode(positionMode) { }
	};

	struct RelocateObjectArgs
	{
		cocos2d::Node* relocatedObject;

		RelocateObjectArgs() : relocatedObject(nullptr) { }
		RelocateObjectArgs(cocos2d::Node* relocatedObject) : relocatedObject(relocatedObject) { }
	};

	struct StateWriteArgs
	{
		void* owner;
		std::string key;
		cocos2d::Value value;

		StateWriteArgs(void* owner, std::string key, cocos2d::Value value) : owner(owner), key(key), value(value) { }
	};

	static void TriggerCollisionMapUpdated();
	static void TriggerBroadCastMapObjectState(std::string eventName, cocos2d::ValueMap args);
	static void TriggerMoveObjectToTopLayer(RelocateObjectArgs args);
	static void TriggerUnbindObject(RelocateObjectArgs args);
	static void TriggerElevateObject(RelocateObjectArgs args);
	static void TriggerObjectSpawn(RequestObjectSpawnArgs args);
	static void TriggerObjectSpawnDelegator(RequestObjectSpawnDelegatorArgs args);
	static void TriggerWriteObjectState(StateWriteArgs args);

	template<class T>
	static void QueryObjects(QueryObjectsArgs<T> args)
	{
		cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
			ObjectEvents::EventQueryObject,
			&args
		);
	}
};
