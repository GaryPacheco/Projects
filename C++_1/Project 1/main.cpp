/*
 * Number Guessing Game
 * A game whre the user tries to guess the-
 * computer's number. The user gets 5 tires.
 * Gary Pacheco
 * Date created: 8/31/2010
 * Last date modified: 9/2/2010
 *
 * SOURCES USED
 */


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // Clock time on computer
    srand(time(0));

    int userNumber = 0; // this is a variable declaration
    int numberOfGuesses = 0;
    int randomNumber = 0;
    int highNumber = 10;
    int difficultyLevel = 0;


    // print a welcome message
    cout << "Welcome to My ultimate number guessing game!" << endl << endl;

    cout << "You have 3 tries to test your intelligence, Good Luck!" << endl << endl;

       cout << "Please choose difficulty between 1-3: ";

       cin >> difficultyLevel;

        if (difficultyLevel == 1)
        highNumber = 5;
        else if (difficultyLevel == 2)
        highNumber = 10;
        else if (difficultyLevel == 3)
        highNumber = 100;


    // generate a random number
    randomNumber = rand() % highNumber + 1;


// THIS IS FOR TESTING- REMOVE AFTER TEST [cerr << "The random number chosen is -> " << randomNumber << endl;]

     // Loop: too keep guessing
        while (userNumber != randomNumber && numberOfGuesses < 3)


{

    // prompt the user for input
            cout << "\nPlease enter a number between 1-" << highNumber << ": ";

    // read in input
            cin >> userNumber;

    // add 1 to the count of the number guesses
            numberOfGuesses++;

    // If number goes over 10
        if (userNumber >  highNumber)
            cout << "\nYou guess is over " << highNumber << ". Choose a lower number." << endl <<endl;

    // compare the user input with the random number
            // the numbers match -- you win
        if (userNumber == randomNumber)
             cout << "\nSweet! You win!\n" << endl;

    // user input is lower
        else if (userNumber < randomNumber)
            cout << "\nYou're number is to low!\n" << endl;

    // user input is higher
        else
            cout << "\nYou're number is to high!\n" << endl;


}

    if (userNumber == randomNumber)
    cout << "So you won! Can you do it again? \n\n";

    else
    cout << "Ooh I'm sorry, but you failed! \n\n";

    string junk = "";
    cout << "Please hit enter to continue";
    getline (cin, junk);
    getline (cin, junk);

    return 0;
}
