#include "user_input_handler.h"

// Default Constructor
UserInputHandler::UserInputHandler() {
  //Error Message: If input is not valid
  invalid_char_ = "Invalid Character\n";
  //Error Message: If characters are not allowed
  char_not_allowed_= "Character Not Allowed\n";
  //Error Message: Not a valid integer
  invalid_int_ = "Invalid Integer\n";
  //Error Message: Integer is higher than maximum value
  high_int_ = "Integer Out Of Range Of Maximum Alotted Value\n";
  //Error Message: Integer is loer than minimum value
  low_int_ = "Integer Out Of Range Of Minimum Alotted Value\n";
  //Error Message: Not a vaild floating-point value
  invalid_double_ = "Invalid Floating-Point Value\n";
  //Error Message: Not a valid bool
  invalid_bool_ = "Invalid Boolean Value\n";
  //Error Message: String is longer than alloted value
  too_long_string_ = "String Is Over Maximum Number Of Characters\n";
  //Error Message: User doesnt allow and empty string
  empty_string_ = "Empty String Not Allowed\n";
}

// Input Functions
char UserInputHandler::GetSingleCharacter(string input_string) {
  bool quit = false;
  while (quit == false) {
    cout << "Please enter a single character: ";
    cin >> input_string;
    if (input_string.length() > 1)
      cerr << char_not_allowed_;
    else if (!isalpha(input_string[0]))
      cerr << invalid_char_;
    else
      quit = true;
  }
  return input_string[0];
}

int UserInputHandler::GetInteger(int int_min, int int_max) {
  bool quit = false;
  int user_input = 0;
  int error_value = 0;
  string a_string = "";
  stringstream ss;
  while (quit == false) {
    user_input = 0;
    error_value = 0;
    cout << "Please enter an integer between " << int_min << " & " << int_max;
    cout << ": ";
    cin >> a_string;
    if (a_string[0] == '-' || isdigit(a_string[0])) {
      for (unsigned int i = 1; i < a_string.length(); i++) {
        if (!isdigit(a_string[i])) {
          cerr << invalid_int_;
          error_value = 1;
        }
        if (error_value == 0) {
          ss << a_string;
          ss >> user_input;
          if (user_input > int_max)
            cerr << high_int_;
          else if (user_input < int_min)
            cerr << low_int_;
          else
            quit = true;
        }
      }
    }
  }
  return user_input;
}

double UserInputHandler::GetDouble() {
  double float_value = 0;
  bool quit = false;
  string a_string = "";
  stringstream ss;
  while (quit == false) {
    float_value = 0;
    int error_value = 0;
    cout << "Please enter a floating-point value: ";
    cin >> a_string;
    if (a_string[0] == '-' || isdigit(a_string[0])) {
      for (unsigned int i = 1; i < a_string.length(); i++) {
        if (!isdigit(a_string[i]) && a_string[i] != '.') {
          cerr << invalid_int_;
          error_value = 1;
        }
      }
      if (error_value == 0) {
        ss << a_string;
        ss >> float_value;
        quit = true;
      }
    } else {
      cerr << invalid_int_;
    }
  }
  return float_value;
}

bool UserInputHandler::GetBoolean() {
  string bool_input = "";
  bool answer = false;
  bool quit = false;
  while (quit == false) {
    cout << "Please enter a boolean value Ex. True, False or (T,F): ";
    cin >> bool_input;
    for (unsigned int i = 0; i < bool_input.length(); i++)
      bool_input = toupper(bool_input[i]);
    if (bool_input == "T" || bool_input == "TRUE") {
      quit = true;
      answer = true;
    } else if (bool_input == "F" || bool_input == "FALSE") {
      quit = true;
      answer = false;
    } else {
        cerr << invalid_bool_;
        quit = false;
    }
  }
  return answer;
}

string UserInputHandler::GetString(int max_chars, bool catch_string) {
  string the_string = "";
  int str_length = 0;
  bool quit = false;
  while (quit == false) {
    cout << "Please enter a string: ";
    cin >> the_string;
    cin >> max_chars;
    str_length = the_string.length();
    if (the_string.length() == 0 && catch_string == false) {
      cerr << empty_string_;
    } else if (max_chars != -1) {
      if (str_length > max_chars)
        cerr << too_long_string_;
      else
        quit = true;
    } else {
      quit = true;
    }
  }
  return the_string;
}
