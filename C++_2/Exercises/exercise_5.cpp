/*
 * Name        : exercise_5.cpp
 * Author      : Gary Pacheco
 * Description : Practicing Functions
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <streambuf>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
 * Hello - Display "Hello world!" to stdout (no newline character after)
 *
 * @return void - Void
 */
void Hello();

/*
 * PrintMessage - Display message to stdout (no newline character after)
 *
 * @param const string &message - Message to be manipulated
 * @return void - VOID
 */
void PrintMessage(const string &message);

/*
 * GetAnswers - Returns the value 42
 *
 * @return int - Returns 42
 */
int GetAnswer();

/*
 * FindLarger - Returns the larger of the two values
 *
 * @param const int &n1 - Holds the first value passed in
 * @param const int &n2 - Holds the second value passed in
 * @return int - The largest value
 */
int FindLarger(const int &n1, const int &n2);

/*
 * GetStats - Returns the length of the string and counts the amount of
 * capital characters in n1 and the amount of lowercase charactrs in n2.
 *
 * @param const string &a_string - String to be manipulated
 * @param int &n1 - Holds value of capital characters
 * @param int &n2 - Holds value of lowercase characters
 * @return int - Length of the passed in string
 */
int GetStats(const string &a_string, int &n1, int &n2);

/*
 * BuildMessage - Checks the passed in bool for value and concatinates the string
 * and stdout based on whether the bool is true or false.
 *
 * @param const string &a_string - String to be manipulated
 *                                 (Default value = empty string)
 * @param const bool &a_bool - Sets what message says based on true or false
 *                             (Default value = false)
 * @return string - The concatinated message a_string and std output 
 *
 */
string BuildMessage(const string &a_string = "", const bool &a_bool = false);


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

// -------FUNCTIONS-------
void Hello() {
  cout << "Hello world!";
}

void PrintMessage(const string &message) {
  cout << message;
}

int GetAnswer() {
  return 42;
}

int FindLarger(const int &n1, const int &n2) {
  if (n1 >= n2)
    return n1;
  else
    return n2;
}

int GetStats(const string &a_string, int &n1, int &n2) {
  n1 = 0;
  n2 = 0;
  for (unsigned int i = 0; i < a_string.length(); i++) {
    if (isupper(a_string[i])) {
      n1++;
    }
    else if (islower(a_string[i])) {
      n2++;
    }
  }
  return a_string.length();
}

string BuildMessage(const string &a_string, const bool &a_bool) {
  
  string new_string = a_string;
  if (a_string == "") {
    return new_string = "Message: empty";
  } 
  else if (a_bool == true) {
    for (unsigned int i = 0; i < a_string.length(); i++) {
      new_string[i] = toupper(new_string[i]);
    }
    new_string = "Message: " + new_string;
    return new_string;
  }
  else {
    new_string = "Message: " + a_string;
    return new_string;
  }
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  std::streambuf* oldCout = cout.rdbuf();
  std::ostringstream captureCout;
  cout.rdbuf(captureCout.rdbuf());
  Hello();
  cout.rdbuf(oldCout);
  Test(captureCout.str() == "Hello world!", "Hello()");
  captureCout.str("");
  cout.rdbuf(captureCout.rdbuf());
  PrintMessage("Hello again!");
  cout.rdbuf(oldCout);
  Test(captureCout.str() == "Hello again!", "PrintMessage(\"Hello again!\")");
  Test(GetAnswer() == 42, "GetAnswer()");
  Test(FindLarger(-1, 1) == 1, "FindLarger(-1, 1)");
  Test(FindLarger(1, -1) == 1, "FindLarger(1, -1)");
  Test(FindLarger(1, 1) == 1, "FindLarger(1, 1)");
  int upper = 0, lower = 0;
  Test(GetStats("abc ABC", upper, lower) == 7 && upper == 3 && lower == 3,
       "GetStats(\"abc 123\", upper, lower)");
  Test(GetStats("abc", upper, lower) == 3 && upper == 0 && lower == 3,
       "GetStats(\"abc\", upper, lower)");
  Test(GetStats("ABC", upper, lower) == 3 && upper == 3 && lower == 0,
       "GetStats(\"ABC\", upper, lower)");
  Test(GetStats("", upper, lower) == 0 && upper == 0 && lower == 0,
       "GetStats(\"\", upper, lower)");
  Test(BuildMessage("hello") == "Message: hello", "BuildMessage(\"hello\")");
  Test(BuildMessage("hello", true) == "Message: HELLO",
       "BuildMessage(\"hello\", true)");
  Test(BuildMessage("HELLO", false) == "Message: HELLO",
       "BuildMessage(\"HELLO\", false)");
  Test(BuildMessage("HELLO", true) == "Message: HELLO",
       "BuildMessage(\"HELLO\", true)");
  Test(BuildMessage() == "Message: empty", "BuildMessage()");
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
