/*
 * Name        : exercise_7.cpp
 * Author      : Gary Pacheco
 * Description : working with filestreams and handling file input/output
 */
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::map;

/*
 * Open and read the contents of a text file. Each line of the
 * file will contain a single integer of possible values 10, 20,
 * 30, 40, or 50. Perform the following operations on the input values:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * </ul>
 * @param string filename - A string containing the name of the file to
 *                          be processed
 * @return bool - True if filename was successfully opened and processed,
 *                else false
 */
bool ProcessFile(string filename);

// For testing (DO NOT ALTER)
map<int, int> counters;
void OnTen();
void OnTwenty();
void OnThirty();
void OnForty();
void OnFifty();
void OnError();
void Test(bool test, string more_info = "");
void UnitTest();

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

//FUNCTION DEFINITIONS
bool ProcessFile(string filename) {
  ifstream fin;
  int input = 0;
  fin.open(filename.c_str());
  if (fin.fail())
    return false;
  while (fin >> input) {
    switch(input) {
      case 10:
        OnTen();
      break;
      case 20:
        OnTwenty();
      break;
      case 30:
        OnThirty();
      break;
      case 40:
        OnForty();
      break;
      case 50:
        OnFifty();
      break;
      default:
        OnError();
      break;
    }
  }
  fin.close();
  return true;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  counters[10] = 0, counters[20] = 0, counters[20] = 0,
  counters[40] = 0, counters[50] = 0,  counters[99] = 0;
  ProcessFile("exercise_7_input.txt");
  Test(counters[10] == 15, "Counting 10s");
  Test(counters[20] == 14, "Counting 20s");
  Test(counters[30] == 13, "Counting 30s");
  Test(counters[40] == 12, "Counting 40s");
  Test(counters[50] == 11, "Counting 50s");
  Test(counters[99] == 35, "Counting Errors");
  Test(ProcessFile("non-existent-file.txt") == false,
       "Processing non-existent file");
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

void OnTen() {
  counters[10]++;
}

void OnTwenty() {
  counters[20]++;
}

void OnThirty() {
  counters[30]++;
}

void OnForty() {
  counters[40]++;
}

void OnFifty() {
  counters[50]++;
}

void OnError() {
  counters[99]++;
}
