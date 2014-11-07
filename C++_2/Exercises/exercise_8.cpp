/*
 * Name        : exercise_8.cpp
 * Author      : Gary Pacheco
 * Description : Working with Command Line Arguments
 */
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::map;
using std::stringstream;

/*
 * Process the argv array (command-line arguments to the program). Ignore
 * argv[0] as that is the program name. Perform the following operations on
 * the input values:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * @param int argc - Contains the number of arguments passed to the program
 *                   on the command-line
 * @param char *argv[] - An array containing the command-line arguments
 */
void ProcessArguments(int argc, char *argv[]);

// For testing (DO NOT ALTER)
map<int, int> counters;
void OnTen();
void OnTwenty();
void OnThirty();
void OnForty();
void OnFifty();
void OnError();
void Test(bool test, string more_info = "");
void UnitTest(int argc, char *argv[]);
bool CheckArgs(int argc, char* argv[]);

// Program Execution Starts Here
int main(int argc, char* argv[]) {
  // To test your code (DO NOT ALTER)
  UnitTest(argc, argv);
  // This ends program execution
  return 0;
}

//FUNCTION DEFINITION
void ProcessArguments(int argc, char *argv[]) {
  string holder;
  for (int i = 1; i < argc; i++) {
    holder = argv[i];
    if (holder == "10")
      OnTen();
    else if (holder == "20") 
      OnTwenty();
    else if (holder== "30")
      OnThirty();
    else if (holder == "40")
      OnForty();
    else if (holder == "50")
      OnFifty();
    else
      OnError();
  }
}

// For testing (DO NOT ALTER)
void UnitTest(int argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "teacher") == 0 && CheckArgs(argc, argv)) {
    string temp = "This unit test will test some of your code:\n";
    cout << temp << string(temp.length() - 1, '-') << endl;
    // Tests
    counters[10] = 0, counters[20] = 0, counters[20] = 0, counters[40] = 0,
    counters[50] = 0;
    counters[99] = 0;

    ProcessArguments(argc, argv);

    Test(counters[10] == 1, "Counting 10s");
    Test(counters[20] == 1, "Counting 20s");
    Test(counters[30] == 1, "Counting 30s");
    Test(counters[40] == 1, "Counting 40s");
    Test(counters[50] == 1, "Counting 50s");
    Test(counters[99] == 2, "Counting Errors");
  } else {
    cout << "\nRun program with the following argument list:\n";
    cout << "\n\t\"teacher 10 20 30 40 50 60\"\n";
    cout << "\nto run the UNIT TEST.\n\n";
  }
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

bool CheckArgs(int argc, char* argv[]) {
  if (argc == 8) {
    // convert the argv[2] to argv[7] contents to integers
    int *temps = new int[6];
    stringstream ss;
    for (int i = 0, j = 2; i < 6; i++, j++) {
      ss.str(argv[j]);
      ss >> temps[i];
      ss.clear();
    }

    // check to see that argv[2] to argv[7] match the expected launch
    // UNIT TEST values
    for (int i = 0, j = 10; i < 6; i++, j += 10) {
      if (temps[i] != j)
        return false;
    }

    delete[] temps;

    return true;
  }
  return false;
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
