/*
 * Rock Paper Scissors Game
 * A game whre the user tries to guess if the-
 * computer chose rock paper or scissors.
 * Gary Pacheco
 * Date created: 9/9/2010
 * Last date modified: 9/9/2010
 *
 * SOURCES USED
 */

#include <iostream>
#include "CinReader.h"
#include <ctime>
#include <cstdlib>

using namespace std;

CinReader reader;

int main()
{
    srand(time(0));                             // Computer time

    cout << "Welcome, Test your wits against my Rock, Paper, Scissors Game!" << endl;   // Welcome Message!

int randomNumber = 0;

    randomNumber = rand() % 3 + 1;       // Generates a random Number


char computerChoice = 'z';                      // Varialbe to convert numbers into letters.

   if (randomNumber = 1)                            // Converts number 1 to the letter "r"
        computerChoice = 'r';
   else if (randomNumber = 2)                      // Converts number 2  to the letter "s"
        computerChoice = 's';
   else if (randomNumber = 3)                      // Converts number 3 to the letter "p"
        computerChoice = 'p';

cout << "(R)ock, (S)cissors, or (P)aper? ";      // Asks the player to Choose (R), (S), or (P)


   char playerChoice = reader.readChar("RrSsPp");   // Allows the user to only put in R,r,S,s,P,p keys
   playerChoice = tolower(playerChoice);            // Upper cases user input to help program understand the input


    if (playerChoice == 'r')                        // User enters R shows they chose Rock
        cout<< "\nYou Chose \"Rock\"\n";
    else if (playerChoice == 's')                   // User enters S shows they chose Scissors
        cout << "\nYou Chose \"Scissors\"\n";
    else if (playerChoice == 'p')                   // User enters P shows they chose Paper
        cout << "\nYou Chose \"Paper\"\n";

    if (playerChoice == 'r' && computerChoice == 's')
        cout << "Alright, You won! The computer chose: " << computerChoice << "cissors\n";
    else if (playerChoice == 's' && computerChoice == 'p')
        cout << "Alright, You won! The computer chose: " << computerChoice << "aper\n";
    else if (playerChoice == 'p' && computerChoice == 'r')
        cout << "Alright, You won! The computer chose: " << computerChoice << "ock\n";
    else if(playerChoice == 'r' && computerChoice == 'p')
        cout << "I am sorry, but you lost...Sucka! The computer chose: " << computerChoice << "aper\n";
    else if (playerChoice == 's' && computerChoice == 'r')
        cout << "I am sorry, but you lost...Sucka! The computer chose: " << computerChoice << "ock\n";
    else if (playerChoice == 'p' && computerChoice == 's')
        cout << "I am sorry, but you lost...Sucka! The computer chose: " << computerChoice << "cissors\n";
    else if (playerChoice == 'r' && computerChoice == 'r')
        cout << "You tied! The computer chose: " << computerChoice << "ock\n";
    else if (playerChoice == 's' && computerChoice == 's')
        cout << "You tied! The computer chose: " << computerChoice << "cissors\n";
    else if  (playerChoice == 'p' && computerChoice == 'p')
        cout << "You tied! The computer chose: " << computerChoice << "aper\n";

    return 0;

}
