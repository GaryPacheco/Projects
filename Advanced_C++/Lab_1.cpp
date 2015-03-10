/*
 * Name        : Lab_1.cpp
 * Author      : Gary Pacheco
 * Description : Basic arithmetic and string manipulation using arrays and 
 *				 functions
 * Sources     : Luke Sathrum, cplusplus.com
 *
 */
 
#include <iostream>
#include <cmath>
#include <string>
#include <climits>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//FUNCTION PROTOTYPES
 /*
  * CountCharacters counts the number of alphabetic and numeric characters in 
  * the user input which is passed in as a string
  * @param string s1 - string being passed in and manipulated
  * @param int &alpha_count - counts number of alphabetic characters
  * @param int &num_count - counts number of numeric characters
  */ 
void CountCharacters(string s1, int &alpha_count, int &num_count);

 /*
  * UpAndDown - Manipulates the string where the first character is capitalized,
  * the second character lowercase, the third is capitalized, etc...
  * @param string s1 - String being passed in and manipulated
  * @return string - The manipulated string
  */
string UpAndDown(string s1);
 /*
  * CountWords - Counts the words in a string delimited of the space character
  * @param string s1 - String being passed in and manipulated
  * @return int - The number of words in string
  */
int CountWords(string s1);
 /*
  * Average - Computes the average of the values in the array. 
  * the user input which is passed in as a string
  * @param int int_array - Values being passed in an array
  * @param int array_size - Size of the array
  * @return int - The computed average
  */
int Average(int int_array[], int array_size);
 /*
  * Minimum - Computes the minimum of the values in the array
  * @param int int_array - Values being passed in an array
  * @param int array_size - Size of the array
  * @return int - The computed minimum
  */
int Minimum(int int_array[], int array_size);
 /*
  * Maximum - Computes the maximum of the values in the array
  * @param int int_array - Values being passed in an array
  * @param int array_size - Size of the array
  * @return int - The computed maximum
  */
int Maximum(int int_array[], int array_size);

//TESTING
void UnitTest();
void Test(bool test, string more_info = "");

//Program starts here
 int main() {
  UnitTest();
  return 0;
}
 
//Functions
void CountCharacters(string s1, int &alpha_count, int &num_count) {
  alpha_count = 0;
  num_count = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (isalpha(s1[i]))
	    alpha_count++;
  	else if (isdigit(s1[i]))
	    num_count++;
  }
}

string UpAndDown(string s1) {
  for (int i = 0; i < s1.length(); i++) {
    if (isalpha(s1[i])) {
      s1[i] = toupper(s1[i]);
    }
  }
  for (int i = 1; i < s1.length(); i += 2) {
    if (isalpha(s1[i])) {
      s1[i] = tolower(s1[i]);
    }
  }
  return s1;
}

int CountWords(string s1) {
  int count = 1;
  if (s1 == "") {
    count = 0;
    return count;
  }
  else {
    for (int i = 0; i < s1.length(); i++) {
      if (isspace(s1[i])) {
        count++;
      }
    }
  }
  return count;
}

int Average(int int_array[], int array_size) {
  int num = 0;
	for(int i = 0; i < array_size; i++)
	  num = num + int_array[i];
	num = num / array_size;
	return num;
}

int Minimum(int int_array[], int array_size) {
  int num = int_array[0];
	for(int i = 0; i < array_size; i++)
	{
		if (int_array[i] < num)
			num = int_array[i];
	}
	return num;
}

int Maximum(int int_array[], int array_size) {
  int num = int_array[0];
	for(int i = 0; i < array_size; i++)
	{
		num = int_array[i];
		if (int_array[i] > num)
			num = int_array[i];
	}
	return num;
}

//FOR TESTING
void UnitTest() {
  cout << "\nSTARTING UNIT TEST\n\n";

  int n1 = 0, n2 = 0;
  CountCharacters("", n1, n2);
  Test((n1 == 0) && (n2 == 0), "CountCharacters(empty string)");
  CountCharacters("hello", n1, n2);
  Test((n1 == 5) && (n2 == 0), "CountCharacters(\"hello\")");
  CountCharacters("12345", n1, n2);
  Test((n1 == 0) && (n2 == 5), "CountCharacters(\"12345\")");
  CountCharacters("hello 12345", n1, n2);
  Test((n1 == 5) && (n2 == 5), "CountCharacters(\"hello 12345\")");
  CountCharacters("&,.", n1, n2);
  Test((n1 == 0) && (n2 == 0), "CountCharacters(\"&,.\")");
  string s;
  s = UpAndDown("hello");
  Test(s == "HeLlO", "UpAndDown(\"hello\")");
  s = UpAndDown("HeLlO");
  Test(s == "HeLlO", "UpAndDown(\"HeLlO\")");
  s = UpAndDown("hElLo");
  Test(s == "HeLlO", "UpAndDown(\"hElLo\")");
  s = UpAndDown("");
  Test(s == "", "UpAndDown(\"\")");
  s = UpAndDown("a");
  Test(s == "A", "UpAndDown(\"a\")");
  Test(CountWords("") == 0, "CountWords(\"\")");
  Test(CountWords("hello") == 1, "CountWords(\"hello\")");
  Test(CountWords("hello,world") == 1, "CountWords(\"hello world\")");
  Test(CountWords("hello world") == 2, "CountWords(\"hello world\")");
  Test(CountWords("hello, world") == 2, "CountWords(\"hello, world\")");
  int values[] = { 10, 20, 30 };
  Test(Average(values, 3) == 20, "ComputeAverage([10,20,30])");
  values[0] = 0, values[1] = 0, values[2] = 0;
  Test(Average(values, 3) == 0, "ComputeAverage([0,0,0])");
  values[0] = 5, values[1] = 7, values[2] = 11;
  Test(Average(values, 3) == 7, "ComputeAverage([5,7,11])");
  values[0] = -10, values[1] = -20, values[2] = -30;
  Test(Average(values, 3) == -20, "ComputeAverage([-10,-20,-30])");
  values[0] = -5, values[1] = 0, values[2] = 5;
  Test(Average(values, 3) == 0, "ComputeAverage([-5,0,5])");
  values[0] = -1, values[1] = 0, values[2] = 1;
  Test(Minimum(values, 3) == -1, "FindMinValue([-1,0,1])");
  values[0] = -3, values[1] = -2, values[2] = -1;
  Test(Minimum(values, 3) == -3, "FindMinValue([-3,-2,-1])");
  values[0] = 0, values[1] = 1, values[2] = 2;
  Test(Minimum(values, 3) == 0, "FindMinValue([0,1,2])");
  values[0] = 1, values[1] = 1, values[2] = 1;
  Test(Minimum(values, 3) == 1, "FindMinValue([1,1,1])");
  values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
  Test(Minimum(values, 3) == INT_MAX,
       "FindMinValue([INT_MAX,INT_MAX,INT_MAX])");
  values[0] = -1, values[1] = 0, values[2] = 1;
  Test(Maximum(values, 3) == 1, "FindMaxValue([-1,0,1])");
  values[0] = -3, values[1] = -2, values[2] = -1;
  Test(Maximum(values, 3) == -1, "FindMaxValue([-3,-2,-1])");
  values[0] = 0, values[1] = 1, values[2] = 2;
  Test(Maximum(values, 3) == 2, "FindMaxValue([0,1,2])");
  values[0] = 1, values[1] = 1, values[2] = 1;
  Test(Maximum(values, 3) == 1, "FindMaxValue([1,1,1])");
  values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
  Test(Maximum(values, 3) == INT_MIN,
       "FindMaxValue([INT_MIN,INT_MIN,INT_MIN])");

  cout << "\nUNIT TEST COMPLETE\n\n";
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << test_number << " " << more_info << "!\n";
  test_number++;
}