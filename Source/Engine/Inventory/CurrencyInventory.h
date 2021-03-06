#pragma once

#include "cocos/base/CCValue.h"

#include "Engine/SmartNode.h"

class CurrencyInventory : public SmartNode
{
public:
	static CurrencyInventory* create(std::string saveKey = "");
	static CurrencyInventory* create(std::map<std::string, int> currency, std::string saveKey = "");

	int getCurrencyCount(std::string currencyKey);
	void removeCurrency(std::string currencyKey, int count);
	void addCurrency(std::string currencyKey, int count);

protected:
	CurrencyInventory(std::map<std::string, int> currency, std::string saveKey = "");
	virtual ~CurrencyInventory();

	void onEnter() override;
	void initializeListeners() override;

	void deserialize(const cocos2d::ValueMap& valueMap);

private:
	typedef SmartNode super;

	void save();
	void load();
	
	cocos2d::ValueMap currencyMap;

	std::string saveKey;
};
