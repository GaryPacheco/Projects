#include "SmugglerShip.h"

//Constructors
SmugglerShip::SmugglerShip ()
:captainName("No Name"), shipName("SS Smuggler"), legalCargoCapacity(5), legalCargo(new TradeItem[legalCargoCapacity]),
 illegalCargoCapacity(3), illegalCargo(new TradeItem[illegalCargoCapacity]), legalCargoUsed(0), illegalCargoUsed(0), astros(100)
{
}

SmugglerShip::SmugglerShip (string newCaptainName, string newShipName, unsigned int newAstros)
:legalCargoUsed(0), illegalCargoUsed(0), legalCargo(new TradeItem[legalCargoCapacity]),
 illegalCargo(new TradeItem[illegalCargoCapacity])
{
}

//Destructor
SmugglerShip::~SmugglerShip()
{
//Free Memory of dynamic array legalCargo & illegalCargo
delete[] legalCargo;
delete[] illegalCargo;
}

//Sets
void SmugglerShip::setCaptainName(string newCaptainName)
{
	captainName = newCaptainName;
}

void SmugglerShip::setShipName(string newShipName)
{
	shipName = newShipName;
}

void SmugglerShip::addAstros(unsigned int numAstros)
{
	astros = astros + numAstros;
}

bool SmugglerShip::spendAstros(unsigned int numAstros)
{
	bool canSpend = false;
	if (numAstros <= astros)
	{
		canSpend = true;
		astros = astros - numAstros;
	}
	else
	{	
		canSpend = false;
	}
	return canSpend;
}


bool SmugglerShip::addCargo(TradeItem item, char type)
{

	return false;
}

/*
void SmugglerShip::checkCargo()
{

}
*/

//Gets
string SmugglerShip::getCaptainName()
{
	return captainName;
}

string SmugglerShip::getShipName()
{
	return shipName;
}

unsigned int SmugglerShip::getAstros()
{
	return astros;
}

unsigned int SmugglerShip::getCargoCapacity(char type)
{
	if (type == 'L' || type == 'l')
		return legalCargoCapacity;
	else
		return illegalCargoCapacity;
}

unsigned int SmugglerShip::getLegalCargoUsed()
{
	return legalCargoUsed;
}


unsigned int SmugglerShip::getIllegalCargoUsed()
{
	return illegalCargoUsed;
}
