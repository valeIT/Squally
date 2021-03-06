#pragma once

#include "Engine/Deserializers/Objects/ObjectDeserializer.h"

class MiniMapTerrainDeserializer : public ObjectDeserializer
{
public:
	static MiniMapTerrainDeserializer* create();

	static const std::string MapKeyTypeTerrain;

protected:
	MiniMapTerrainDeserializer();
	virtual ~MiniMapTerrainDeserializer();

private:
	typedef ObjectDeserializer super;

	void deserialize(ObjectDeserializer::ObjectDeserializationRequestArgs* args);

	std::map<std::string, std::function<GameObject*(cocos2d::ValueMap)>> deserializers;
};
