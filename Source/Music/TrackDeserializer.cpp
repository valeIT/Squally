#include "TrackDeserializer.h"

#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Engine/GlobalDirector.h"
#include "Engine/Sound/Music.h"
#include "Engine/Utils/LogUtils.h"

#include "Music/Tracks.h"

using namespace cocos2d;

TrackDeserializer* TrackDeserializer::instance = nullptr;

TrackDeserializer* TrackDeserializer::getInstance()
{
	if (TrackDeserializer::instance == nullptr)
	{
		TrackDeserializer::instance = new TrackDeserializer();

		instance->autorelease();
	}

	return TrackDeserializer::instance;
}

void TrackDeserializer::registerGlobalNode()
{
	// Register this class globally so that it can always listen for events
	GlobalDirector::getInstance()->registerGlobalNode(TrackDeserializer::getInstance());
}

TrackDeserializer::TrackDeserializer()
{
	this->deserializers = std::map<std::string, std::function<Track*(SmartNode*)>>();

	// Hexus Cards
	this->deserializers[Heartbeat::TrackKey] = [=](SmartNode* owner) { return (Track*)Heartbeat::create(owner); };
	this->deserializers[WeWillGetThereTogether::TrackKey] = [=](SmartNode* owner) { return (Track*)WeWillGetThereTogether::create(owner); };
}

TrackDeserializer::~TrackDeserializer()
{
}

void TrackDeserializer::initializeListeners()
{
	super::initializeListeners();

	EventListenerCustom* deserializationRequestListener = EventListenerCustom::create(
		SoundEvents::EventRequestTrackDeserialization,
		[=](EventCustom* eventCustom)
		{
			SoundEvents::RequestTrackDeserializationArgs* args = static_cast<SoundEvents::RequestTrackDeserializationArgs*>(eventCustom->getUserData());
			
			if (args != nullptr)
			{
				TrackDeserializer::deserialize(*args); 
			}
		}
	);

	this->addGlobalEventListener(deserializationRequestListener);
}

void TrackDeserializer::deserialize(SoundEvents::RequestTrackDeserializationArgs args)
{
	std::string serializationKey = args.trackSerializationKey;

	if (args.onTrackDeserializedCallback != nullptr && this->deserializers.find(serializationKey) != this->deserializers.end())
	{
		args.onTrackDeserializedCallback(this->deserializers[serializationKey](args.owner));
	}
	else
	{
		LogUtils::logError("Unknown track encountered: " + serializationKey);
	}
}
