/*
 * Name        : user_input_handler.h
 * Author      : Gary Pacheco
 * Description : Class Header File, Program handles input robustly
 */
#ifndef PACHECO_USER_INPUT_HANDLER_H
#define PACHECO_USER_INPUT_HANDLER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <locale>
#include <cctype>
#include <sstream>
using std::stringstream;
using std::toupper;
using std::cout;
using std::cin;
using std::string;
using std::cerr;

/*
* Class UserInputHandler
* A class that handles users input robustly and sends errors if it does input
* does not meet specific criteria.
*/
class UserInputHandler {
 public:
  /* Constructor
   * Default constructor sets the values for the error messages
   */
  UserInputHandler();
  /*
   * GetSingleCharacter
   * Reads a char from input and handles errors if input is not a char
   * @param string input_string - Defaults Empty String, string users
   *                              input too.
   */
  char GetSingleCharacter(string input_string = "");
  /*
   * GetInteger
   * Reads an integer from input and handles errors if input is not an integer
   * Throws an error if value is higher or lower than set ranges
   * @param int int_min - Minimum value the inputed integer can be
   * @param int int_max - Maximum value the inputed integer can be
   */
  int GetInteger(int int_min = -32767, int int_max = 32767);
  /*
   * GetDouble
   * Reads a floating-point value from input. Throws an error if input is not
   * a double
   */
  double GetDouble();
  /*
   * GetBoolean
   * Reads a bool from input. Handles if user enters True or False and allows
   * for case insenstivity
   */
  bool GetBoolean();
  /*
   * GetString
   * Reads a string from input. Throws errors if string is larger than maximum
   * allotted characters and if users allow empty strings.
   * @param int max_chars - Defaults -1 which sets no maximum value for
   *                        characters. Sets maximum amount of characters 
   *                        string can be.
   * @param bool catch_string - Allows users to set if they want empty strings
   */
  string GetString(int max_chars = -1 , bool catch_string = true);
 private:
    //Error Messages
    string invalid_char_;
    string char_not_allowed_;
    string invalid_int_;
    string high_int_;
    string low_int_;
    string invalid_double_;
    string invalid_bool_;
    string too_long_string_;
    string empty_string_;
};
#endif /* PACHECO_USER_INPUT_HANDLER_H */
