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
 * Cheyanne Taylor-Pacheco
 * Boyd Trolinger
 * Cplusplus.com
 *
 */
 //Library includes
#include <cassert>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

/*
 * countCharacters
 * This function counts the number of alphabetic characters and
 * digits in the user's string input.
 * @param userInput passes the string user enter to be manipulated
 * @param numAlpha stores the number of alphabetic characters in user's input
 * @param numDigit stores the number of digits in user's input
 */
void countCharacters (string userInput, int& numAlpha, int& numDigit);

/* upAndDown
 * This function humptifies the users string inputed.
 * @param userInput passes the string user enter to be manipulated.
 * @return string returns manipulated string to be displayed.
 */
string upAndDown (string userInput);

/* 
 *countWords
 * This function counts the words from users string input.
 * @param userInput passes the string user enter to be manipulated.
 * @return int returns number of words counted in string inputed.
 */
int countWords (string userInput);

/*
 * computeAverage
 * This function finds the average of the users values.
 * @param intArray passes in the values to find average.
 * @param arraySize passes the size to be compared.
 * @return int returns average of values counted in the array.
 */
int computeAverage (int intArray [], int arraySize);

/*
 * findMinValue
 * This function finds the mimimum value in users array.
 * @param intArray passes in the values to find the minimum.
 * @param arraySize passes the size to be compared.
 * @return int returns minimum of values found in the array.
 */
int findMinValue (int intArray [], int arraySize);

/*
 * findMaxValue
 * This function finds the maximum value in users array.
 * @param intArray passes in the values to find the maximum.
 * @param arraySize passes the size to be compared.
 * @return int returns maximum of values found in the array.
 */
int findMaxValue (int intArray [], int arraySize);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

//Programs main function
int main (int argc, char* argv[])
{
	unittest();
	
	return 0;
}

/*
 * Unit testing functions. Do not alter.
 */
void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";

	int n1=0, n2=0;

	try {
		countCharacters("", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 0));
		cout << "Passed TEST 1: countCharacters(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 1 #\n";
	}

	try {
		countCharacters("hello", n1, n2);
		btassert<bool>((n1 == 5) && (n2 == 0));
		cout << "Passed TEST 2: countCharacters(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 2 #\n";
	}

	try {
		countCharacters("12345", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 5));
		cout << "Passed TEST 3: countCharacters(\"12345\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 3 #\n";
	}

	try {
		countCharacters("hello 12345", n1, n2);
		btassert<bool>((n1 == 5) && (n2 == 5));
		cout << "Passed TEST 4: countCharacters(\"hello 12345\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 4 #\n";
	}

	try {
		countCharacters("&,.", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 0));
		cout << "Passed TEST 5: countCharacters(\"&,.\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 5 #\n";
	}

	string s;

	try {
		s = upAndDown("hello");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 6: upAndDown(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 6 #\n";
	}

	try {
		s = upAndDown("HeLlO");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 7: upAndDown(\"HeLlO\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 7 #\n";
	}

	try {
		s = upAndDown("hElLo");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 8: upAndDown(\"hElLo\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 8 #\n";
	}

	try {
		s = upAndDown("");
		btassert<bool>(s == "");
		cout << "Passed TEST 9: upAndDown(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 9 #\n";
	}

	try {
		s = upAndDown("a");
		btassert<bool>(s == "A");
		cout << "Passed TEST 10: upAndDown(\"a\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 10 #\n";
	}

	try {
		btassert<bool>(countWords("") == 0);
		cout << "Passed TEST 11: countWords(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 11 #\n";
	}

	try {
		btassert<bool>(countWords("hello") == 1);
		cout << "Passed TEST 12: countWords(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 12 #\n";
	}

	try {
		btassert<bool>(countWords("hello,world") == 1);
		cout << "Passed TEST 13: countWords(\"hello world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 13 #\n";
	}

	try {
		btassert<bool>(countWords("hello world") == 2);
		cout << "Passed TEST 14: countWords(\"hello world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 14 #\n";
	}

	try {
		btassert<bool>(countWords("hello, world") == 2);
		cout << "Passed TEST 15: countWords(\"hello, world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 15 #\n";
	}

	int values [] = {10, 20, 30};
	try {
		btassert<bool>(computeAverage(values, 3) == 20);
		cout << "Passed TEST 16: computeAverage([10,20,30])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 16 #\n";
	}

	values[0] = 0, values[1] = 0, values[2] = 0;
	try {
		btassert<bool>(computeAverage(values, 3) == 0);
		cout << "Passed TEST 17: computeAverage([0,0,0])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 17 #\n";
	}

	values[0] = 5, values[1] = 7, values[2] = 11;
	try {
		btassert<bool>(computeAverage(values, 3) == 7);
		cout << "Passed TEST 18: computeAverages([5,7,11])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 18 #\n";
	}

	values[0] = -10, values[1] = -20, values[2] = -30;
	try {
		btassert<bool>(computeAverage(values, 3) == -20);
		cout << "Passed TEST 19: computeAverages([-10,-20,-30])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 19 #\n";
	}

	values[0] = -5, values[1] = 0, values[2] = 5;
	try {
		btassert<bool>(computeAverage(values, 3) == 0);
		cout << "Passed TEST 20: computeAverages([-5,0,5])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 20 #\n";
	}

	values[0] = -1, values[1] = 0, values[2] = 1;
	try {
		btassert<bool>(findMinValue(values, 3) == -1);
		cout << "Passed TEST 21: findMinValue([-1,0,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 21 #\n";
	}

	values[0] = -3, values[1] = -2, values[2] = -1;
	try {
		btassert<bool>(findMinValue(values, 3) == -3);
		cout << "Passed TEST 22: findMinValue([-3,-2,-1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 22 #\n";
	}

	values[0] = 0, values[1] = 1, values[2] = 2;
	try {
		btassert<bool>(findMinValue(values, 3) == 0);
		cout << "Passed TEST 23: findMinValue([0,1,2])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 23 #\n";
	}

	values[0] = 1, values[1] = 1, values[2] = 1;
	try {
		btassert<bool>(findMinValue(values, 3) == 1);
		cout << "Passed TEST 24: findMinValue([1,1,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 24 #\n";
	}

	values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
	try {
		btassert<bool>(findMinValue(values, 3) == INT_MAX);
		cout << "Passed TEST 25: findMinValue([INT_MAX,INT_MAX,INT_MAX])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 25 #\n";
	}

	values[0] = -1, values[1] = 0, values[2] = 1;
	try {
		btassert<bool>(findMaxValue(values, 3) == 1);
		cout << "Passed TEST 26: findMaxValue([-1,0,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 26 #\n";
	}

	values[0] = -3, values[1] = -2, values[2] = -1;
	try {
		btassert<bool>(findMaxValue(values, 3) == -1);
		cout << "Passed TEST 27: findMaxValue([-3,-2,-1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 27 #\n";
	}

	values[0] = 0, values[1] = 1, values[2] = 2;
	try {
		btassert<bool>(findMaxValue(values, 3) == 2);
		cout << "Passed TEST 28: findMaxValue([0,1,2])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 28 #\n";
	}

	values[0] = 1, values[1] = 1, values[2] = 1;
	try {
		btassert<bool>(findMaxValue(values, 3) == 1);
		cout << "Passed TEST 29: findMaxValue([1,1,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 29 #\n";
	}

	values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
	try {
		btassert<bool>(findMaxValue(values, 3) == INT_MIN);
		cout << "Passed TEST 30: findMaxValue([INT_MIN,INT_MIN,INT_MIN])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 30 #\n";
	}

	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
	if (!assertion)
		throw X();
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