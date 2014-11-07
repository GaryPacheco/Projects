#pragma once
#include "TradeItem.h"
#include <iostream>
#include <string>

using namespace std;

class SmugglerShip
{
	public:
		SmugglerShip();
		SmugglerShip(string newCaptainName, string shipName, unsigned int newAstros);
		~SmugglerShip();
		
		void setCaptainName (string newCaptainName);
		void setShipName (string newShipName);
		void addAstros (unsigned int numAstros);
		bool spendAstros (unsigned int numAstros);
		bool addCargo(TradeItem item, char type);
		//void checkCargo(unsigned int item);
		
		string getCaptainName();
		string getShipName();
		unsigned int getAstros();
		unsigned int getCargoCapacity(char type);
		unsigned int getLegalCargoUsed();
		unsigned int getIllegalCargoUsed();
	
	private:
		string captainName;
		string shipName;
		unsigned int astros;
		unsigned int legalCargoCapacity;
		unsigned int legalCargoUsed;
		unsigned int illegalCargoCapacity;
		unsigned int illegalCargoUsed;
		TradeItem junk;
		TradeItem* legalCargo;
		TradeItem* illegalCargo;
};