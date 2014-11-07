#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "calculator.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;

void ClearScreen();
void UnitTest(Calculator test);

int main() {
  cout.setf(std::ios::right);
  int choice;
  double initial;
  cout << "(1) Interactive Test\n"
      << "(2) Interactive Test with initial value\n"
      << "Any other input to test the Accessor" << endl;
  cin >> choice;
  if (choice == 1) {
    Calculator my_calculator;
    UnitTest(my_calculator);
  } else if (choice == 2) {
    cout << "Enter an initial value: ";
    cin >> initial;
    Calculator my_calculator(initial);
    UnitTest(my_calculator);
  } else {
    Calculator my_calculator(5.25);
    cout << "Should be 5.25: " << my_calculator.value() << endl;
  }
}

void UnitTest(Calculator test) {
  char choice;
  double input;
  do {
    ClearScreen();
    cout << "--------------------\n" << "|" << setw(18) << test.ToString()
        << "|\n" << "--------------------" << endl;
    cout << "Which Operation to Perform? (+, -, *, /, ^)\n"
         << "Can also choose:\n" << "(1) Reset the calculator value\n"
         << "(2) Set the calculator value\n" << "(3) Exit\n";
    cin >> choice;
    switch (choice) {
      case '+':
        cout << test.ToString() << " + ";
        cin >> input;
        test.Add(input);
        break;
      case '-':
        cout << test.ToString() << " - ";
        cin >> input;
        test.Subtract(input);
        break;
      case '*':
        cout << test.ToString() << " * ";
        cin >> input;
        test.Multiply(input);
        break;
      case '/':
        cout << test.ToString() << " / ";
        cin >> input;
        test.Divide(input);
        break;
      case '^':
        cout << test.ToString() << "^";
        cin >> input;
        test.Exponent(input);
        break;
      case '1':
        test.Reset();
        break;
      case '2':
        cout << "Enter the value to set the calculator to: ";
        cin >> input;
        test.set_value(input);
        break;
    }
  } while (choice != '3');
}

// For testing (DO NOT ALTER)
void ClearScreen() {
#ifdef WIN32
  system("cls");
#else
  system("clear");
#endif
}
