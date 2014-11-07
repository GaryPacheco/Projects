#include "TradeItem.h"

//functions
TradeItem::TradeItem ()
:itemName("Empty"), itemValue(0), isContraband(false)
{
}

TradeItem::TradeItem (string newItemName, unsigned int newItemValue, bool newIsContraband)
: itemName(newItemName), itemValue(newItemValue), isContraband(newIsContraband)
{

}

TradeItem::~TradeItem()
{
}

void TradeItem::setItemName(string newItemName)
{
 itemName = newItemName;
}

void TradeItem::setItemValue(unsigned int newItemValue)
{
	itemValue = newItemValue;
}

void TradeItem::setIsContraband(bool newIsContraband)
{
	isContraband = newIsContraband;
}

string TradeItem::getItemName()
{
	return itemName;
}

unsigned int TradeItem::getItemValue()
{
	return itemValue;
}

bool TradeItem::getIsContraband()
{
	return isContraband;
}
