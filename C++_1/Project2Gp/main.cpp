/*
 * Rock Paper Scissors Game
 * A game whre the user tries to guess if the-
 * computer chose rock paper or scissors and beat
 * the computer by choosing the correct one.
 * Gary Pacheco
 * Date created: 9/9/2010
 * Last date modified: 9/16/2010
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
    srand(time(0));                                 // Computer Time

    int randomNumber = 0;
    char computerChoice = 'z';                      // Varialbe to convert numbers into letters.
    int numberOfplays = 0;
    char replay = 'y';
    int numberofWins = 0;
    int numberofLosses = 0;
    int numberofTies = 0;
    int rockCount = 0;
    int scissorCount = 0;
    int paperCount= 0;

    cout << "Welcome, Test your wits against my Rock, Paper, Scissors Game!\n" << endl;   // Welcome Message!

    while (replay == 'y' || replay == 'Y')

    {

        randomNumber = rand() % 3 + 1;                   // Generates a random Number


        if (randomNumber == 1)                             // Converts number 1 to the letter "r"
            computerChoice = 'r';
        else if (randomNumber == 2)                        // Converts number 2  to the letter "s"
            computerChoice = 's';
        else if (randomNumber == 3)                        // Converts number 3 to the letter "p"
            computerChoice = 'p';


        cout << "\nPlease Choose: (R)ock, (S)cissors, or (P)aper? ";      // Asks the player to Choose (R), (S), or (P)

        char playerChoice = reader.readChar("RrSsPp");   // Allows the user to only put in R,r,S,s,P,p keys
        playerChoice = tolower(playerChoice);            // Upper cases user input to help program understand the input

        numberOfplays ++;
        switch (playerChoice)
        {

        case 'r':
            cout << "\nYou Chose \"Rock\"\n";          // User enters R shows they chose Rock
            rockCount ++;
            break;
        case 's':
            cout << "\nYou Chose \"Scissors\"\n";        // User enters S shows they chose Scissors
            scissorCount ++;
            break;
        case 'p':
            cout << "\nYou Chose \"Paper\"\n";          // User enters P shows they chose Paper
            paperCount ++;
            break;
        }

        if (playerChoice == 'r' && computerChoice == 's')              // Compares Players choice to Computers choice to see who wins
        {
            numberofWins ++;
            cout << "Alright, You won! The computer chose: " << computerChoice << "cissors\n";
        }
        else if (playerChoice == 's' && computerChoice == 'p')
        {
            numberofWins ++;
            cout << "Alright, You won! The computer chose: " << computerChoice << "aper\n";
        }
        else if (playerChoice == 'p' && computerChoice == 'r')
        {
            numberofWins ++;
            cout << "Alright, You won! The computer chose: " << computerChoice << "ock\n";
        }
        else if(playerChoice == 'r' && computerChoice == 'p')
        {
            numberofLosses ++;
            cout << "I am sorry, but you lost... The computer chose: " << computerChoice << "aper\n";
        }
        else if (playerChoice == 's' && computerChoice == 'r')
        {
            numberofLosses ++;
            cout << "I am sorry, but you lost... The computer chose: " << computerChoice << "ock\n";
        }
        else if (playerChoice == 'p' && computerChoice == 's')
        {
            numberofLosses ++;
            cout << "I am sorry, but you lost... The computer chose: " << computerChoice << "cissors\n";
        }
        else if (playerChoice == 'r' && computerChoice == 'r')
        {
            cout << "You tied! The computer chose: " << computerChoice << "ock\n";
            numberofTies ++;
        }
        else if (playerChoice == 's' && computerChoice == 's')
        {
            cout << "You tied! The computer chose: " << computerChoice << "cissors\n";
            numberofTies ++;
        }
        else if  (playerChoice == 'p' && computerChoice == 'p')
        {
            cout << "You tied! The computer chose: " << computerChoice << "aper\n";
            numberofTies ++;
        }

        cout << "\nWould you like to play again? [Y]es or [N]o: ";
        replay = reader.readChar ("YyNn");

        if (replay == 'n' || replay == 'N')
        {
            cout << "Thank you for playing!\n\nYou have played (" << numberOfplays << ") time[s]\n";
            cout << "\nNumber of Wins (" << numberofWins << ")";
            cout << " \nNumber of Losses (" << numberofLosses << ")";
            cout << " \nNumber of Ties (" << numberofTies << ").";
            cout << "\nChose Paper (" << paperCount << ") time[s].";
            cout << "\nChose Rock (" << rockCount << ") time[s]";
            cout << "\nChose Scissors (" << scissorCount << ") time[s]";
        }
    }

    string junk = "";
    cout << "\n\nPress Enter To Exit";
    getline (cin, junk);


    return 0;

}
