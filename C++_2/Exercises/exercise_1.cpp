/*
 * Name        : exercise_1.cpp
 * Author      : Gary Pacheco
 * Description : Exercise 1 to review basic syntax
 */

#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
void UnitTest(string user_name, char programmed_before, char my_character);
void Test(bool test, int number);

// Program Execution Starts Here
int main() {
  // (1) Declare a string variable named user_name
    string user_name;

  // (2) Declare a character variable named programmed_before and another named
  //     my_character. Initialize both of them to the value 'z'
    char programmed_before = 'z';
    char my_character = 'z';
    
  // (3) Display a welcome message to standard output
    cout << "Hello and welcome!\n";
    
  // (4) Prompt the user for a name
    cout << "Please Enter Your Name:\n";

  // (5) Read the name from standard input and store in the variable user_name
    cin >> user_name;

  // (6) Display the message "Nice to meet you, NAME" where NAME is replaced
  //     with the value of user_name
    cout << "Nice to meet you, " << user_name << "." << endl;
    
  // (7) Ask the user if they have programmed before. Make sure you inform them
  //     that you want the answer as a single character (y/n)
    cout << "Have you ever programmed? (y/n): ";

  // (8): Read in the answer from standard input and store in the variable
  //      programmed_before
    cin >> programmed_before;


  // For testing (DO NOT ALTER)
  UnitTest(user_name, programmed_before, my_character);

  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest(string user_name, char programmed_before, char my_character) {
  cout << string(5, '\n');
  string temp = "This unit test will test some of your code\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  Test(true, 1);
  Test(my_character == 'z', 2);
  Test(user_name != "", 5);
  Test(programmed_before == tolower('y')
       || programmed_before == tolower('n'), 8);
}
// For testing (DO NOT ALTER)
void Test(bool test, int number) {
  if (test)
    cout << "PASSSED TEST " << number << "!\n";
  else
    cout << "FAILED  TEST " << number << "!\n";
}
