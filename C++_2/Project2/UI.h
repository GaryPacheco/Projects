#pragma once
#include <iostream>
#include <cstdlib>
#include "TradeItem.h" 
#include "SmugglerShip.h"
#include "CinReader.h"

using namespace std;

class UI
{
	public:
		void go();
		void smugglerShip(SmugglerShip& s1, TradeItem& c1);
		void tradeItem();
		//template <typename X, typename A>
		//void btassert(A assertion);
		//void unitTest();
		
	private:
		SmugglerShip ship;
};