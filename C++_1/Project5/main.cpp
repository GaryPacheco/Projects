/*
 * Project 5
 * A person chooses two numbers between 1-1000
 * The program then finds those numbers
 * factors, the GCD, and the LCM,
 * using money values for the small number,
 * and seconds for the large number.
 * Gary Pacheco
 * Date created: 10/19/2010
 * Last date modified: 10/28/2010
 *
 * SOURCES USED
 *Cheyanne Taylor
 *Boyd Trollinger
 */

#include <iostream>
#include "CinReader.h"

using namespace std;

CinReader reader;

void factors (int number);
bool prime (int number);
bool gcd (int a, int b, int& result);
int lcm (int a, int b, int g);
void maximums (int number, char type= 'S');

int main()
{
    cout << "\nWelcome to my project 5.\n\n";

    cout << "Please enter a number between 1 - 1000: ";
    int numberOne = reader.readInt(1,1000);

    cout << "Please enter another number between 1 - 1000: ";
    int numberTwo = reader.readInt(1,1000);

    factors (numberOne);
    factors (numberTwo);

    if (prime(numberOne) == true)
        cout << endl << numberOne << " is a prime number.\n";
    else
        cout << endl << numberOne << " is NOT a prime number.\n";

    if (prime(numberTwo) == true)
        cout << numberTwo << " is a prime number.\n" << endl;
    else
        cout << numberTwo << " is NOT a prime number.\n" << endl;


    int result = 0;
    if (gcd (numberOne, numberTwo, result) == true)
    {
        cout << "\nThe gcd of " << numberOne <<" and " << numberTwo << " is: " << result << endl;
        cout << "\nThe least common multiple of " << numberOne <<" and " << numberTwo << " is: ";
        cout << lcm (numberOne, numberTwo, result) << endl;
    }
    else
    {
        cout << "No useable gcd for "<< numberOne << " and " << numberTwo << "." << endl;
    }

    if (numberOne > numberTwo)
    {
        maximums (numberTwo,'D');
        maximums (numberOne);
    }
    else
    {
        maximums (numberOne,'D');
        maximums (numberTwo);
    }

    string junk = "";
    cout << "Please hit enter to continue";
    getline (cin, junk);

    return 0;
}

void factors (int number)
{
    cout << "\nFactors of " << number << ": ";
    for (int i = 1; i<=number; i++)
    {
        if (number % i == 0)
            cout << i << ' ';
    }
    cout << endl;
}

bool prime (int number)
{
    int numberOfFactors = 0;
    for (int i = 1; i<=number; i++)
    {
        if (number % i == 0)
            numberOfFactors ++;
    }
    if (numberOfFactors <= 2)
        return true;
    else
        return false;
}

bool gcd (int a, int b, int& result)
{
    int t = 0;


    if (b > a)
    {
        t = a;
        a = b;
        b = t;
    }

    int tb = b;
    while (b !=0)
    {
        // cout << "a = " << a << ", b = " << b << ", t = " << t << endl;
        t = b;
        b = a % b;
        a = t;
    }

    result = a;
    if (result > 1 && result < tb)
        return true;
    else
        return false;
}

int lcm (int a, int b, int g)
{
    return ((a*b)/g);
}

void maximums (int number, char type)
{
    if (type == 'D')
    {
        int quarters = 0;
        int dimes = 0;
        int nickels = 0;
        int pennies = 0;

        cout << endl << number << " in cents is: ";

        quarters = number / 25;
        number = number % 25;

        dimes = number / 10;
        number = number % 10;

        nickels = number / 5;
        number = number % 5;

        pennies = number;

        cout << endl << quarters << " quarters, " << dimes << " dimes, ";
        cout << endl << nickels << " nickels, " << pennies << " pennies" << endl;
    }

    else if (type == 'S')
    {
        int minutes = 0;
        int seconds = 0;

        cout << endl << number << " in time is: ";
        minutes = number /60;
        number = number % 60;

        seconds = number;

        cout << endl << minutes << " minutes, " << seconds << " seconds" << endl;
    }
}
