#pragma once
#include <iostream>
#include <string>

using namespace std;

class TradeItem
{
	public:
		TradeItem();
		TradeItem(string newItemName, unsigned int newItemValue, bool newIsContraband);
		~TradeItem();
		
		void setItemName(string newItemName);
		void setItemValue(unsigned int newItemValue);
		void setIsContraband(bool newIsContraband);
		
		string getItemName();
		unsigned int getItemValue();
		bool getIsContraband();
		
		//only friends look at your privates ;)
		//overloaded operator ==
		//friend ostream& operator== (ostream& outs, const City& c);
		
	private:
		string itemName;
		unsigned int itemValue;
		bool isContraband;
};
