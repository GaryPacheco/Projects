#include "UI.h"
CinReader reader;

void UI::go()
{
	
	//Variables
	int choice = 0;
	bool quit = false;
	int junk = 0;

	//Creating Instances
	TradeItem c1, c2, c3;
	SmugglerShip s1;
	
	while (quit == false)
	{
	
	//Menu Variables
	choice = 0;
	quit = false;

	cout << "What would you like to do?" << endl;
	cout << "[1] Smuggler Ship" << endl;
	cout << "[2] Trade Item" << endl;
	cout << "[3] Run Unit Test" << endl;
	cout << "[0] Quit" << endl;
	cout << "Your choice: ";
	choice = reader.readInt(0,3);

		switch(choice)
		{
			case 1:
				smugglerShip(s1, c1);
			break;
			case 2:
				tradeItem();
			break;
			case 3:
				//unitTest();
			break;
			case 0:
				quit = true;
			break;
		}
	}
	
}

void UI::smugglerShip(SmugglerShip& s1, TradeItem& c1)
{
	bool quit = false;
	string inputName;
	int choice = 0;
	
	while(quit == false)
	{
		system("cls");
		cout << "Manage Ship: " << endl;
		cout << "[1] Add Cargo" << endl;
		cout << "[2] Check Cargo" << endl;
		cout << "[3] Remove Cargo" << endl;
		cout << "[4] Set Captains Name" << endl;
		cout << "[5] Set Ships Name" << endl;
		cout << "[6] Add Astros" << endl;
		cout << "[7] Spend Astros" << endl;
		cout << "[8] View Capacity" << endl;
		cout << "[0] Quit" << endl;
		cout << "Your Choice: ";
		choice = reader.readInt(0,8);
		switch(choice)
		{
			case 1:
				c1.setItemName(reader.readString());
				c1.setItemValue(reader.readInt());
				cout << "[L]egal or [I]llegal" << endl;
				cout << "Your choice: ";
				s1.addCargo(c1, reader.readChar("LlIi"));
			break;
			case 2:
				
			break;
			case 3:
				
			break;
			case 4:
				cout << "Captains Name: " << s1.getCaptainName() << endl;
				cout << "New Name: ";
				inputName = reader.readString();
				s1.setCaptainName(inputName);
			break;
			case 5:
				cout << "Ships Name: " << s1.getShipName() << endl;
				cout << "New Name: ";
				inputName = reader.readString();
				s1.setShipName(inputName);
			break;
			case 6:
				cout << "Current Astros: " << s1.getAstros() << endl;
				cout << "How many Astros would you like to add (0,1000): " << endl;
				s1.addAstros(reader.readInt(0,1000));
			break;
			case 7:
				cout << "Current Astros: " << s1.getAstros() << endl;
				cout << "How many Astros would you like to spend?" << endl;
				s1.spendAstros(reader.readInt(0,s1.getAstros()));
			break;
			case 8:
				system("cls");
				cout << "[L]egal Cargo or [I]llegal Cargo" << endl;
				cout << "Your Choice: ";
				s1.getCargoCapacity(reader.readChar("LlIi"));
			break;
			case 0:
				quit = true;
			break;
		}
	}
}

void UI::tradeItem()
{

}

/*
void UI::unitTest()
{
	cout << "\nSTARTING UNIT TEST\n\n";
	
	SmugglerShip s("Captain Peabody", "SS Unit Test", 3, 3, 100);
	
	cout << "** TESTING SMUGGLERSHIP **\n\n";
	
	try {
		btassert<bool>(s.getCaptainName() == "Captain Peabody");
		cout << "Passed TEST 1: SmugglerShip getCaptainName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 1 SmugglerShip getCaptainName() #\n";
	}
	
	try {
		btassert<bool>(s.getShipName() == "SS Unit Test");
		cout << "Passed TEST 2: SmugglerShip getShipName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 2 SmugglerShip getShipName() #\n";
	}
	
	s.setCaptainName("CAPTAIN PEABODY");
	try {
		btassert<bool>(s.getCaptainName() == "CAPTAIN PEABODY");
		cout << "Passed TEST 3: SmugglerShip setCaptainName()/getCaptainName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 3 SmugglerShip setCaptainName()/getCaptainName() #\n";
	}
	
	s.setShipName("SS UNIT TEST");
	try {
		btassert<bool>(s.getShipName() == "SS UNIT TEST");
		cout << "Passed TEST 4: SmugglerShip setShipName()/getShipName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 4 SmugglerShip setShipName()/getShipName() #\n";
	}
	
	try {
		btassert<bool>(s.getAstros() == 100);
		cout << "Passed TEST 5: SmugglerShip getAstros()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 5 SmugglerShip getAstros() #\n";
	}
	
	s.addAstros(15);
	try {
		btassert<bool>(s.getAstros() == 115);
		cout << "Passed TEST 6: SmugglerShip addAstros(15)/getAstros()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 6 SmugglerShip addAstros(15)/getAstros() #\n";
	}
	
	try {
		btassert<bool>(s.spendAstros(116) == false);
		cout << "Passed TEST 7: SmugglerShip spendAstros(116)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 7 SmugglerShip spendAstros(116) #\n";
	}
	
	s.spendAstros(114);
	try {
		btassert<bool>(s.getAstros() == 1);
		cout << "Passed TEST 8: SmugglerShip spendAstros(114)/getAstros()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 8 SmugglerShip spendAstros(114)/getAstros() #\n";
	}
	
	try {
		btassert<bool>(s.checkCargo(0, 'L') == TradeItem());
		cout << "Passed TEST 9: SmugglerShip checkCargo(0, 'L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 9 SmugglerShip checkCargo(0, 'L') #\n";
	}
	
	try {
		btassert<bool>(s.removeCargo(0, 'L') == TradeItem());
		cout << "Passed TEST 10: SmugglerShip removeCargo(0, 'L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 10 SmugglerShip removeCargo(0, 'L') #\n";
	}
	
	try {
		btassert<bool>(s.checkCargo(0, 'I') == TradeItem());
		cout << "Passed TEST 11: SmugglerShip checkCargo(0, 'I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 11 SmugglerShip checkCargo(0, 'I') #\n";
	}
	
	try {
		btassert<bool>(s.removeCargo(0, 'L') == TradeItem());
		cout << "Passed TEST 12: SmugglerShip removeCargo(0, 'I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 12 SmugglerShip removeCargo(0, 'I') #\n";
	}
	
	s.addCargo(TradeItem("RED", 1), 'L');
	s.addCargo(TradeItem("GREEN", 2), 'L');
	s.addCargo(TradeItem("BLUE", 3), 'L');
	try {
		btassert<bool>(s.addCargo(TradeItem("GOLD", 4), 'L') == false);
		cout << "Passed TEST 13: SmugglerShip addCargo(\"GOLD\",'L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 13 SmugglerShip addCargo(\"GOLD\",'L') #\n";
	}
	
	try {
		btassert<bool>(s.checkCargo(1, 'L') == TradeItem("GREEN", 2));
		cout << "Passed TEST 14: SmugglerShip checkCargo(1, 'L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 14 SmugglerShip checkCargo(1, 'L') #\n";
	}
	
	try {
		btassert<bool>(s.removeCargo(2, 'L') == TradeItem("BLUE", 3));
		cout << "Passed TEST 15: SmugglerShip removeCargo(2, 'L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 15 SmugglerShip removeCargo(2, 'L') #\n";
	}
	
	try {
		btassert<bool>(s.removeCargo(2, 'L') == TradeItem());
		cout << "Passed TEST 16: SmugglerShip removeCargo(2, 'L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 16 SmugglerShip removeCargo(2, 'L') #\n";
	}
	
	try {
		btassert<bool>(s.checkCargo(2, 'L') == TradeItem());
		cout << "Passed TEST 17: SmugglerShip checkCargo(2, 'L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 17 SmugglerShip checkCargo(2, 'L') #\n";
	}
	
	try {
		btassert<bool>(s.addCargo(TradeItem("PURPLE", 5), 'L') == true);
		cout << "Passed TEST 18: SmugglerShip addCargo(\"PURPLE\", 'L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 18 SmugglerShip addCargo(\"PURPLE\", 'L') #\n";
	}
	
	s.addCargo(TradeItem("RED", 1), 'I');
	s.addCargo(TradeItem("GREEN", 2), 'I');
	s.addCargo(TradeItem("BLUE", 3), 'I');
	try {
		btassert<bool>(s.addCargo(TradeItem("GOLD", 4), 'I') == false);
		cout << "Passed TEST 19: SmugglerShip addCargo(\"GOLD\",'I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 19 SmugglerShip addCargo(\"GOLD\",'I') #\n";
	}
	
	try {
		btassert<bool>(s.checkCargo(1, 'I') == TradeItem("GREEN", 2));
		cout << "Passed TEST 20: SmugglerShip checkCargo(1, 'I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 20 SmugglerShip checkCargo(1, 'I') #\n";
	}
	
	try {
		btassert<bool>(s.removeCargo(2, 'I') == TradeItem("BLUE", 3));
		cout << "Passed TEST 21: SmugglerShip removeCargo(2, 'I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 21 SmugglerShip removeCargo(2, 'I') #\n";
	}
	
	try {
		btassert<bool>(s.removeCargo(2, 'I') == TradeItem());
		cout << "Passed TEST 22: SmugglerShip removeCargo(2, 'I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 22 SmugglerShip removeCargo(2, 'I') #\n";
	}
	
	try {
		btassert<bool>(s.checkCargo(2, 'I') == TradeItem());
		cout << "Passed TEST 23: SmugglerShip checkCargo(2, 'I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 23 SmugglerShip checkCargo(2, 'I') #\n";
	}
	
	try {
		btassert<bool>(s.addCargo(TradeItem("PURPLE", 5), 'I') == true);
		cout << "Passed TEST 24: SmugglerShip addCargo(\"PURPLE\", 'I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 24 SmugglerShip addCargo(\"PURPLE\", 'I') #\n";
	}
	
	try {
		btassert<bool>(s.getCapacity('L') == 3);
		cout << "Passed TEST 25: SmugglerShip getCapacity('L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 25 SmugglerShip getCapacity('L') #\n";
	}
	
	try {
		btassert<bool>(s.getCapacity('I') == 3);
		cout << "Passed TEST 26: SmugglerShip getCapacity('I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 26 SmugglerShip getCapacity('I') #\n";
	}
	
	SmugglerShip s1;
	
	try {
		btassert<bool>(s1.getCaptainName() == "No Name");
		cout << "Passed TEST 27: SmugglerShip getCaptainName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 27 SmugglerShip getCaptainName() #\n";
	}
	
	try {
		btassert<bool>(s1.getShipName() == "SS Smuggler");
		cout << "Passed TEST 28: SmugglerShip getShipName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 28 SmugglerShip getShipName() #\n";
	}
	
	try {
		btassert<bool>(s1.getCapacity('L') == 5);
		cout << "Passed TEST 29: SmugglerShip getCapacity('L')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 29 SmugglerShip getCapacity('L') #\n";
	}
	
	try {
		btassert<bool>(s1.getCapacity('I') == 3);
		cout << "Passed TEST 30: SmugglerShip getCapacity('I')\n";
	} catch (bool b) {
		cout << "# FAILED TEST 30 SmugglerShip getCapacity('I') #\n";
	}
	
	try {
		btassert<bool>(s1.getAstros() == 100);
		cout << "Passed TEST 31: SmugglerShip getAstros()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 31 SmugglerShip getAstros() #\n";
	}
	
	cout << "\n** TESTING TRADE ITEM **\n\n";
	
	TradeItem i;
	
	try {
		btassert<bool>(i.getItemName() == "EMPTY");
		cout << "Passed TEST 32: TradeItem getItemName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 32 TradeItem getItemName() #\n";
	}
	
	try {
		btassert<bool>(i.getItemValue() == 0);
		cout << "Passed TEST 33: TradeItem getItemValue()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 33 TradeItem getItemValue() #\n";
	}
	
	try {
		btassert<bool>(i.getIsContraband() == false);
		cout << "Passed TEST 34: TradeItem getIsContraband()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 34 TradeItem getIsContraband() #\n";
	}
	
	i.setItemName("GREEN");
	try {
		btassert<bool>(i.getItemName() == "GREEN");
		cout << "Passed TEST 35: TradeItem setItemName()/getItemName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 35 TradeItem setItemName()/getItemName() #\n";
	}
	
	i.setItemValue(99);
	try {
		btassert<bool>(i.getItemValue() == 99);
		cout << "Passed TEST 36: TradeItem setItemValue(99)/getItemValue()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 36 TradeItem setItemValue(99)/getItemValue() #\n";
	}
	
	i.setIsContraband(true);
	try {
		btassert<bool>(i.getIsContraband() == true);
		cout << "Passed TEST 37: TradeItem setIsContraband(true)/getIsContraband()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 37 TradeItem setIsContraband(true)/getIsContraband() #\n";
	}
	
	TradeItem i1("RED", 1, true);
	
	try {
		btassert<bool>(i1.getItemName() == "RED");
		cout << "Passed TEST 38: TradeItem getItemName()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 38 TradeItem getItemName() #\n";
	}
	
	try {
		btassert<bool>(i1.getItemValue() == 1);
		cout << "Passed TEST 39: TradeItem getItemValue()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 39 TradeItem getItemValue() #\n";
	}
	
	try {
		btassert<bool>(i1.getIsContraband() == true);
		cout << "Passed TEST 40: TradeItem getIsContraband()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 40 TradeItem getIsContraband() #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}
*/