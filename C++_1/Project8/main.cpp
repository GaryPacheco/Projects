/*
 * Main.CPP: Main is responsible for the users menu.
 * Also for calling the functions to do the tasks.
 *
 * Program:
 * A magical Genie turned computerized!
 * User has the options to name their genie whatever they want
 * and Has the options to choose tasks that the genie will
 * preform, such as roll two d6 dice, Tell how much a tip
 * would be at a certain cost, and your daily adventure(personally made).
 *
 * Gary Pacheco
 * Date created: 12/7/2010
 * Last date modified: 12/14/2010
 *
 * SOURCES USED
 *Cheyanne Taylor
 *Boyd Trollinger
 *Luke S.
 */
#include <iostream>
#include "CinReader.h"
#include "Genie.h"
#include <cstdlib>
#include <ctime>
using namespace std;

CinReader reader;

int main()
{
    bool quit = false;
    srand(time(0));
    Genie* myGenie = new Genie;
    //Genie myGenie;

    cout << "Please Enter Name of Genie: ";
    myGenie->name = reader.readString(false);

    cout << "\nThe Genie's Name is: " << myGenie->name << endl;

    myGenie->luckyNumbers();


    while (quit == false)
    {
        cout << "What would you like " << myGenie ->name << " to do?\n";
        cout << "[1]Roll two D6 dice\n";
        cout << "[2]Check tip percentage\n";
        cout << "[3]Today's adventure\n";
        cout << "[0]Leave " << myGenie->name << ".\n\n";
        cout << "Your choice: ";
        int choice = reader.readInt(0,3);
        switch(choice)
        {
        case 1:
            myGenie ->dieCounter();
            break;
        case 2:
            myGenie->tipPercent(); // Add strings in functions!
            break;
        case 3:
            myGenie->adventure();
            break;
        case 0:
            quit = true;
            break;
        }
    }



    delete myGenie;
    return 0;
}
