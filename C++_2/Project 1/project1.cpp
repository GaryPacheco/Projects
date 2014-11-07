/*
 * Project One
 * This program is used to review the techniques
 * of functions, strings, arrays, and basic C++
 * handling.
 *
 * Gary Pacheco
 * Date created: 04/23/2013
 * Last date modified: 
 *
 * SOURCES USED:
 * Boyd Trolinger
 * Absolute C++
 * Cheyanne Taylor-Pacheco
 *
 *
 *g++ project1.cpp -o projec1.exe
 *project1
 */
 
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
 * This function counts the number of alphabetic characters and
 * digits in the user's string input.
 * @param userInput passes the string user enter to be manipulated
 * @param numAlpha stores the number of alphabetic characters in user's input
 * @param numDigit stores the number of digits in user's input
 */
void countCharacters(string userInput, int& numAlpha, int& numDigit);
string upAndDown(string userInput);
int countWords(string userInput);
int computeAverage(int intArray[], int arraySize);
int findMinValue(int intArray[], int arraySize);
int findMaxValue(int intArray[], int arraySize);

int main(int argc, char * argv[])
{
//Variables
bool quit = false;
int choice = 0;
string userInput;
int numAlpha = 0;
int numDigit = 0;
int arraySize = 0;
int intArray [arraySize];
string junk;

//Input to collect string and array size
system("cls");
cout << "\t\tWelcome to pRoJeCt OnE\n" << endl;
cout << "Please Enter A String: ";
getline(cin, userInput);
cout << "Please Create An Array Size: ";
cin >> arraySize;

//Array to read numbers inputed
for(int i=0; i < arraySize; i++)
{
	cout << "Please Enter Number [" << i+1 << "] In The Array: ";
	cin >> intArray[i];
}

//Menus Loop
while(quit == false)
{
	cout << "\nWhat would you like to do?" << endl;
	cout << "[1] Count character" << endl;
	cout << "[2] Capitalize & lowercase every other character" << endl;
	cout << "[3] Count words" << endl;
	cout << "[4] Compute average" << endl;
	cout << "[5] Identify smallest" << endl;
	cout << "[6] Identify largest" << endl;
	cout << "[0] Quit" << endl;
	cout << "Your choice: ";
	cin >> choice;
	
	 switch(choice)
	 {
		 case 1:
			system("cls");
			countCharacters(userInput, numAlpha, numDigit);
			cout << "Number of Alphabetic: " << numAlpha << endl;
			cout << "Number of Digits: " << numDigit << endl;
		 break;
		 case 2:
			system("cls");
			cout << "Manipulated String: " << upAndDown(userInput) << endl << endl;			
		 break;
		 case 3:
			system("cls");
			cout << "Number of Words In String: " << countWords(userInput) << endl;
		 break;
		 case 4:
			system("cls");
			cout<< "The average of your values: " << computeAverage(intArray, arraySize) << endl;
		 break;
		 case 5:
			system("cls");
			cout << "The minimum value in the array: " << findMinValue(intArray, arraySize) << endl;
		 break;
		 case 6:
			system("cls");
			cout << "The maximum value in the array: " << findMaxValue(intArray, arraySize) << endl;
		 break;
		 case 0:
			quit = true;
		 break;
	 }
}

return 0;
}
void countCharacters(string userInput, int& numAlpha, int& numDigit)
{
	numAlpha = 0;
	numDigit = 0;
	
	for(int i=0; i < userInput.length(); i++)
	{
		if (isalpha(userInput[i]))
			numAlpha++;
		else if (isdigit(userInput[i]))
			numDigit++;
	}
}
string upAndDown(string userInput)
{
	for(int i=0; i < userInput.length(); i++)
	{
		userInput[i] = toupper(userInput[i]);		
	}
	for(int i=1; i < userInput.length(); i+=2)
	{
		userInput[i] = tolower(userInput[i]);
	}

	return userInput;
}
int countWords(string userInput)
{
	int word = 1;
	if (isspace(userInput[0]))
		word = 0;
	if (userInput == (""))
		word = 0;
	for(int i=0; i < userInput.length(); i++)
	{
		if(isspace(userInput[i]))
			word++;
	}
	return word;
}
int computeAverage(int intArray[], int arraySize)
{
	int aNum = 0;
	for(int i=0; i < arraySize; i++)
		aNum = aNum + intArray[i];
	aNum = aNum / arraySize;
	return aNum;
}
int findMinValue(int intArray[], int arraySize)
{
	int aNum = intArray[0];
	for(int i=0; i < arraySize; i++)
	{
		if (intArray[i] < aNum)
			aNum = intArray[i];
	}
	return aNum;
}
int findMaxValue(int intArray[], int arraySize)
{
	int aNum = intArray[0];
	for(int i=0; i < arraySize; i++)
	{
		aNum = intArray[i];
		if (intArray[i] > aNum)
			aNum = intArray[i];
	}
	return aNum;
}