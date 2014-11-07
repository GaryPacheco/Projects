/*
 * Name        : exercise_4.cpp
 * Author      : Gary Pacheco
 * Description : Using branching statements, looping statements and string and
 *               character functions to complete the functions
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ios_base;
using std::boolalpha;

// For testing (DO NOT ALTER)
void InteractiveTest();
void UnitTest();
void Test(bool test, int number, string more_info = "");
void ClearScreen();

// Function Prototypes (DO NOT ALTER)
string MakeString(string label, double value, char separator);
char StringToChar(string value);
int StringToInt(string value);
double StringToDouble(string value);
bool StringToBool(string value);

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  string input;
  cout << "[1] Do interactive test, [2] Skip to unit test: ";
  getline(cin, input);
  if (StringToInt(input) == 1)
    InteractiveTest();

  UnitTest();
  // This ends program execution
  return 0;
}

/*
 * Return a string comprised of a label, followed by a space, followed by a
 * separator character, followed by a space, followed by a floating-point value.
 * For example, label="Temperature", value=41.7, separator=':' will return
 * "Temperature : 41.7".
 * @uses stringstream.
 * @param string label - The label for the value
 * @param double value - The value associated with the label
 * @param char separator - The character that separates the label and the value
 * @return string - Comprised of a label, followed by a space, followed by a
 *                  separator character, followed by a space, followed by a
 *                  floating-point value
 */
string MakeString(string label, double value, char separator) {
  stringstream s_stream;
  s_stream << label << " " << separator << " " << value;
  string string_holder = s_stream.str();
  
  return string_holder;
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Return the first character of a length 1 string. If the value is of
 * length 0 or of length > 1, return the null character ('\0').
 * @param string value - The expected single character
 * @return char - The first character of the string or null character ('\0')
 *                when value is length 0 or value is length > 1
 */
char StringToChar(string value) {
  if (value == "" || value.length() > 1) {
    return '\0';
  }    
  else {
   char c = value.at(0);
   return c;
  }
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected integer value (such as a string
 * captured from stdin) into an integer. If value is not valid as an integer,
 * return 0.
 * @uses stringstream
 * @param string value - The expected integer value
 * @return int - An integer representing the value, or 0 on failure
 */
int StringToInt(string value) {
  // THIS FUNCTION PROVIDED AS AN EXAMPLE
  int ivalue = 0;
  stringstream converter(value);
  converter.exceptions(ios_base::failbit);

  try {
    converter >> ivalue;
  } catch (ios_base::failure f) {
  }

  return ivalue;
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected floating-point value (such as a
 * string captured from stdin) into a double. If value is not valid as a double
 * return 0.
 * @uses stringstream
 * @param string value - The expected floating-point value
 * @return double - A double representing the value, or 0 on failure
 */
double StringToDouble(string value) {
  double double_holder = 0;
  stringstream s_stream(value);
 
  if (!isdigit(s_stream.peek())) {
    return 0;
  }
  else {
    s_stream >> double_holder;
    return double_holder;
  }
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing a boolean value (such as a string captured from
 * stdin) into a bool. Return true if the first character is 'T'
 * (case-insensitive), false if the first character is 'F' (case-insensitive),
 * and false on anything else.
 * @param string value - The expected string to start with either 'T' or 'F'
 * @return bool - If the first character is 'T' (case-insensitive) return true.
 *                If the first character is 'F' (case-insensitive) return false.
 *                Return false on anything else.
 */
bool StringToBool(string value) {
  if (toupper(value.at(0)) == 'T'){
    return true;
  }
  else {
    return false;
  }
}

// For testing (DO NOT ALTER)
void InteractiveTest ()
{
  cout << "\nSTARTING INTERACTIVE TEST\n\n";

  bool quit = false;
  char c = 'z';
  string input;

  while (!quit)
  {
    cout << "! TRY EVERYTHING YOU CAN TO BREAK THESE ON BAD INPUT !\n\n";

    cout << "Enter a char ('z' to stop interactive test): ";
    getline(cin, input);
    c = StringToChar(input);
    if (c == '\0')
      cout << input << " not a valid char\n";
    else if (c == 'z')
      break;
    else
      cout << "Char input: " << c << endl;

    cout << "\nEnter an integer: ";
    getline(cin, input);
    cout << "Integer input: " << StringToInt(input) << endl;

    cout << "\nEnter a double: ";
    getline(cin, input);
    cout << "Double input: " << StringToDouble(input) << endl;

    cout << "\nEnter TRUE or FALSE: ";
    getline(cin, input);
    cout << "Boolean input: " << boolalpha << StringToBool(input) << endl;

    cout << "\nHIT ENTER TO CONTINUE";
    getline(cin, input);
    ClearScreen();
  }

  cout << "\nINTERACTIVE TEST COMPLETE\n\n";
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  Test(MakeString("Temperature", 42.6, ':') == "Temperature : 42.6", 1,
       "MakeString(\"Temperature\", 42.6, ':')");
  Test(MakeString("", 75, ',') == " , 75", 2, "MakeString(\"\", 75, ',')");
  Test(MakeString("Total", 100.05, '=') == "Total = 100.05", 3,
       "MakeString(\"Total\", 100.05, '=')");
  Test(StringToChar("") == '\0', 4, "StringToChar(\"\")");
  Test(StringToChar("yn") == '\0', 5, "StringToChar(\"yn\")");
  Test(StringToChar("X") == 'X', 6, "StringToChar(\"X\")");
  Test(StringToInt("42") == 42, 7, "StringToInt(\"42\")");
  Test(StringToInt("hello") == 0, 8, "StringToInt(\"hello\")");
  Test(StringToInt("") == 0, 9, "StringToInt(\"\")");
  Test(StringToDouble("") == 0, 10, "StringToDouble(\"\")");
  Test(StringToDouble("3.14") == 3.14, 11, "StringToDouble(\"3.14\")");
  Test(StringToDouble("hello") == 0, 12, "StringToDouble(\"hello\")");
  Test(StringToBool("") == false, 13, "StringToBool(\"\")");
  Test(StringToBool("TrUe") == true, 14, "StringToBool(\"TrUe\")");
  Test(StringToBool("FALSE") == false, 15, "StringToBool(\"FALSE\")");
}
// For testing (DO NOT ALTER)
void Test(bool test, int number, string more_info) {
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << number << " " << more_info << "!\n";
}

// For testing (DO NOT ALTER)
void ClearScreen() {
#ifdef WIN32
  system("cls");
#else
  system("clear");
#endif
}
