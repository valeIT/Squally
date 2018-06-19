#include "SerializableMap.h"

SerializableMap::SerializableMap(std::string mapFileName, std::vector<SerializableLayer*>* layers, Size unitSize, Size tileSize)
{
	this->levelMapFileName = mapFileName;
	this->serializableLayers = layers;
	this->mapUnitSize = unitSize;
	this->mapTileSize = tileSize;

	for (auto it = layers->begin(); it != layers->end(); it++)
	{
		this->addChild(*it);
	}
}

SerializableMap::~SerializableMap()
{
	delete(this->serializableLayers);
}

SerializableMap* SerializableMap::deserialize(std::string mapFileName, std::vector<ILayerDeserializer*>* layerDeserializers, std::vector<IObjectDeserializer*>* objectDeserializers)
{
	cocos_experimental::TMXTiledMap* mapRaw = cocos_experimental::TMXTiledMap::create(mapFileName);
	std::map<int, SerializableLayer*> deserializedLayerMap = std::map<int, SerializableLayer*>();
	std::vector<SerializableLayer*>* deserializedLayers = new std::vector<SerializableLayer*>();

	auto onDeserializeCallback = [&](SerializableLayer* layer, int layerIndex) {
		deserializedLayerMap.insert_or_assign(layerIndex, layer);
	};

	// Deserialize layers
	for (auto it = mapRaw->getObjectGroups().begin(); it != mapRaw->getObjectGroups().end(); it++)
	{
		TMXObjectGroup* objectGroup = *it;

		// Ask all deserializers to try to deserialize object
		ILayerDeserializer::LayerDeserializationRequestArgs args = ILayerDeserializer::LayerDeserializationRequestArgs(objectGroup, objectDeserializers, onDeserializeCallback);

		for (auto it = layerDeserializers->begin(); it != layerDeserializers->end(); it++)
		{
			(*it)->onDeserializationRequest(&args);

			if (args.handled)
			{
				break;
			}
		}
	}

	std::vector<cocos_experimental::TMXLayer*> tileLayers = std::vector<cocos_experimental::TMXLayer*>();

	// Pull out tile layers
	for (auto it = mapRaw->getChildren().begin(); it != mapRaw->getChildren().end(); it++)
	{
		cocos_experimental::TMXLayer* tileLayer = dynamic_cast<cocos_experimental::TMXLayer*>(*it);

		if (tileLayer != nullptr)
		{
			tileLayers.push_back(tileLayer);
		}
	}

	// Deserialize tiles (separate step from pulling them out because deserialization removes the child and would ruin the getChildren() iterator)
	for (auto it = tileLayers.begin(); it != tileLayers.end(); it++)
	{
		deserializedLayerMap.insert_or_assign((*it)->layerIndex, SerializableTileLayer::deserialize((*it)));
	}

	// Convert from map to ordered vector
	for (auto it = deserializedLayerMap.begin(); it != deserializedLayerMap.end(); it++)
	{
		deserializedLayers->push_back(it->second);
	}

	SerializableMap* instance = new SerializableMap(mapFileName, deserializedLayers, mapRaw->getMapSize(), mapRaw->getTileSize());

	instance->autorelease();

	return instance;
}

void SerializableMap::serialize()
{
	tinyxml2::XMLDocument* documentRoot = new (std::nothrow)tinyxml2::XMLDocument();
	tinyxml2::XMLDeclaration* declaration = documentRoot->NewDeclaration(("xml version=" + StrUtils::quote("1.0") + " encoding=" + StrUtils::quote("UTF-8")).c_str());
	documentRoot->LinkEndChild(declaration);

	tinyxml2::XMLElement* mapElement = documentRoot->NewElement("map");
	mapElement->SetAttribute("version", "1.0");
	mapElement->SetAttribute("tiledversion", "1.0.3");
	mapElement->SetAttribute("orientation", "orthogonal");
	mapElement->SetAttribute("renderorder", "right-down");
	mapElement->SetAttribute("width", std::to_string((int)this->getMapUnitSize().width).c_str());
	mapElement->SetAttribute("height", std::to_string((int)this->getMapUnitSize().height).c_str());
	mapElement->SetAttribute("tilewidth", std::to_string((int)this->getMapTileSize().width).c_str());
	mapElement->SetAttribute("tileheight", std::to_string((int)this->getMapTileSize().height).c_str());

	tinyxml2::XMLElement* tileSetElement = documentRoot->NewElement("tileset");
	tileSetElement->SetAttribute("firstgid", "1");
	tileSetElement->SetAttribute("name", "TileMap");
	tileSetElement->SetAttribute("tilewidth", std::to_string((int)this->getMapTileSize().width).c_str());
	tileSetElement->SetAttribute("tileheight", std::to_string((int)this->getMapTileSize().height).c_str());
	tileSetElement->SetAttribute("tilecount", std::to_string(1125).c_str()); // TODO
	tileSetElement->SetAttribute("columns", std::to_string(45).c_str()); // TODO

	tinyxml2::XMLElement* gridElement = documentRoot->NewElement("grid");
	gridElement->SetAttribute("orientation", "orthogonal");
	gridElement->SetAttribute("width", std::to_string(64).c_str()); // TODO
	gridElement->SetAttribute("height", std::to_string(64).c_str()); // TODO
	tileSetElement->LinkEndChild(gridElement);

	tinyxml2::XMLElement* imageElement = documentRoot->NewElement("image");
	imageElement->SetAttribute("source", "../Tiles/TileMap.png"); // TODO: Use Resource:: variable, converted to a relative link
	imageElement->SetAttribute("width", std::to_string(5760).c_str()); // TODO
	imageElement->SetAttribute("height", std::to_string(3200).c_str()); // TODO
	tileSetElement->LinkEndChild(imageElement);

	mapElement->LinkEndChild(tileSetElement);

	// Serialize all layers
	for (auto it = this->serializableLayers->begin(); it != this->serializableLayers->end(); it++)
	{
		(*it)->serialize(documentRoot, mapElement);
	}

	// TODO: count obj ids
	mapElement->SetAttribute("nextobjectid", std::to_string(366).c_str());

	documentRoot->LinkEndChild(mapElement);

	bool result = tinyxml2::XML_SUCCESS == documentRoot->SaveFile(CCFileUtils::sharedFileUtils()->fullPathForFilename(this->levelMapFileName + ".dbg").c_str());
}

std::string SerializableMap::getMapFileName()
{
	return this->levelMapFileName;
}

void SerializableMap::hackerModeEnable()
{
	this->setVisible(true);

	for (auto it = this->serializableLayers->begin(); it != this->serializableLayers->end(); it++)
	{
		(*it)->setVisible(false);
	}
}

void SerializableMap::hackerModeDisable()
{
	this->setVisible(true);

	for (auto it = this->serializableLayers->begin(); it != this->serializableLayers->end(); it++)
	{
		(*it)->setVisible(true);
	}
}

Size SerializableMap::getMapSize()
{
	Size unitSize = this->getMapUnitSize();
	Size tileSize = this->getMapTileSize();

	return Size(unitSize.width * tileSize.width, unitSize.height * tileSize.height);
}

Size SerializableMap::getMapUnitSize()
{
	return this->mapUnitSize;
}

Size SerializableMap::getMapTileSize()
{
	return this->mapTileSize;
}

void SerializableMap::appendLayer(SerializableLayer* layer)
{
	this->serializableLayers->push_back(layer);
	this->addChild(layer);
}
