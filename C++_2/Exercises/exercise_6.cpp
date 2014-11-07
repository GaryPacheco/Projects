/*
 * Name        : exercise_6.cpp
 * Author      : Gary pacheco
 * Description : Working with Arrays
 */

#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/*
 * Create a string containing the contents of an array, each element separated
 * by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3".
 * @uses stringstream
 * @param int values[] - An array of integers
 * @param int size - The size of the integer array
 * @param char separator - The separator character to use in the returned
 *                         string. Defaults to ','
 * @return string - A string containing the contents of values separated by the
 *                  specified separator character
 */
string PrepareForDisplay(int values[], int size, char separator = ',');

/*
 * Test to see if an array contains a specified value.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int value - The value to search for within the array
 * @return bool - true if value is found in the array, otherwise false
 */
bool HasValue(int values[], int size, int value);

/*
 * Return the value from an array at a specified index.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int index - The position in the array from which to return a value
 * @param bool error - A flag that will be set to true if index is invalid for
 *                     the array, else it will be set to false
 * @return int - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns 0 and sets error to true
 */
int ValueAt(int values[], int size, int index, bool& error);

/*
 * Return the sum of the values in an integer array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @return int - The sum of the values in the array
 */
int Sum(int values[], int size);

/*
 * Swap the positions of two values in an integer array. The two
 * index values must be valid for the array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @param int index1 - The position of the first value to be swapped
 * @param int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
bool SwapValues(int values[], int size, int index1, int index2);

// For testing (DO NOT ALTER)
void UnitTest();
void Test(bool test, string more_info = "");

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// FUNCTION DEFINITIONS
string PrepareForDisplay(int values[], int size, char separator) {
  stringstream ss;
  string holder;
  for (int i = 0; i < size; i++) {
    ss << values[i];
    if (i < size - 1)
      ss << separator;
  }
  holder = ss.str();
  return holder;
}

bool HasValue(int values[], int size, int value) {
  for (int i = 0; i < size; i++) {
    if (value == values[i])
     return true;
  }
  return false;
}
int ValueAt(int values[], int size, int index, bool& error) {
  if (index >= size) {
    error = true;
    return 0;
  } else {
    error = false;
    return values[index];
  }  
}
int Sum(int values[], int size) {
  int num = 0;
  for (int i = 0; i < size; i++) {
    num += values[i];
  }
  return num;
}
bool SwapValues(int values[], int size, int index1, int index2) {
  int num = 0;
  if (index1 >= size || index2 >= size) {
    return false;
  } else if (index1 < 0 || index2 < 0) {
    return false;
  } else {  
    num = values[index2];
    values[index2] = values[index1];
    values[index1] = num;
    return true;
  }
}
// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  int values[] = { 3, 5, 7, 9, 11 };
  int size = 5;
  Test(PrepareForDisplay(values, size) == "3,5,7,9,11",
       "PrepareForDisplay(values, size)");
  Test(PrepareForDisplay(values, size, ' ') == "3 5 7 9 11",
       "PrepareForDisplay(values, size, ' ')");
  Test(PrepareForDisplay(values, size, ':') == "3:5:7:9:11",
       "PrepareForDisplay(values, size, ':')");
  Test(HasValue(values, size, 0) == false, "HasValue(values, size, 0)");
  Test(HasValue(values, size, 3) == true, "HasValue(values, size, 3)");
  Test(HasValue(values, size, 11) == true, "HasValue(values, size, 11)");
  bool error = true;
  Test(ValueAt(values, size, 0, error) == 3 && error == false,
       "ValueAt(values, size, 0, error)");
  Test(ValueAt(values, size, 5, error) == 0 && error == true,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(values, size, 4, error) == 11 && error == false,
       "ValueAt(values, size, 4, error)");
  Test(Sum(values, size) == 35, "Sum(values, size)");
  Test(Sum(values, 1) == 3, "Sum(values, 1)");
  Test(Sum(values, 0) == 0, "Sum(values, 0)");
  bool success;
  success = SwapValues(values, size, 0, 4);
  Test(values[0] == 11 && values[4] == 3 && success,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(values, size, 1, 3);
  Test(values[1] == 9 && values[3] == 5 && success,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(values, size, 2, 2);
  Test(values[2] == 7 && success, "SwapValues(values, size, 2, 2)");
  success = SwapValues(values, size, -2, 2);
  Test(values[2] == 7 && !success, "SwapValues(values, size, -2, 2)");
  success = SwapValues(values, size, 2, 10);
  Test(values[2] == 7 && !success, "SwapValues(values, size, 2, 10)");
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
