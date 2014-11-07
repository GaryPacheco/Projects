/*
 * Name        : exercise_3.cpp
 * Author      : Gary Pacheco
 * Description : Using branching statements, looping statements and string and
 *               character functions to complete the functions
 */

#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
void UnitTest();
void Test(bool test, int number, string more_info = "");

// Function Prototypes (DO NOT ALTER)
string Goldilocks(string item, int number);
int RockScissorPaper(char player_one, char player_two);
string CharWithAsciiValueAsString(char c);
string ToLower(string input);
string ToUpper(string input);
char GetCharacter(string input, int char_index);

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too big"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid argument)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid argument)
 * @return string - The output string specified in the documentation above
 */
string Goldilocks(string item, int number) {
  if (item == "porridge"){
    if (number == 1)
	  return "This porridge is too hot";
	  
	else if (number == 2)
	  return "This porridge is too cold";
	 
	else
	  return "This porridge is just right";
  }
  else if (item == "chair"){
    if (number == 1 || number == 2)
	  return "This chair is too big";
	
	else
	  return "This chair is just right";
  }
  else {
    if (number == 1)
	  return "This bed is too hard";
	
	else if (number == 2)
	  return "This bed is to soft";
	  
	else
	  return "This bed is just right";
  }
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw
 */
int RockScissorPaper(char player_one, char player_two) {
  switch(player_one){
    case 'R':
	case 'r':
	  if (toupper(player_two) == 'R')
	    return 3;
	  else if (toupper(player_two) == 'S')
	    return 1;
	  else
	    return 2;
	break;
	
	case 'S':
	case 's':
	  if (toupper(player_two) == 'R')
	    return 2;
	  else if (toupper(player_two) == 'S')
	    return 3;
	  else
	    return 1;
	break;
	
	case 'P':
	case 'p':
	  if (toupper(player_two) == 'R')
	    return 1;
	  else if (toupper(player_two) == 'S')
	    return 2;
	  else
	    return 3;
	break;  
  }
}

/*
 * Return a string that contains a character (taken from the parameter
 * c) and its ASCII integer value. For example, If the char passed in is 'A',
 * the function will return '"A 65"
 * @param char c - The char from which an ASCII value will be taken
 * @return string - A string containing the original character argument,
 *                  followed by a space, followed by the ASCII integer value of
 *                  the char
 */
string CharWithAsciiValueAsString(char c) {
  stringstream sout;
  int a = c;
  sout << c << " " << a;
  
  return sout.str();
}

/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) {
  for (int i=0; i < input.length(); i++)
	input.at(i) = tolower(input[i]);
	
  return input;
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 */
string ToUpper(string input) {
  for (int i=0; i < input.length(); i++)
    input.at(i) = toupper(input[i]);
	
  return input;
}

/*
 * Return the character from the input string at index char_index.
 * @param string input - The string from which the character will be taken
 * @param int char_index - The zero-indexed position of the character to return.
 *                         char_index must be >= 0 and < length of input string.
 * @return char - A char containing the character from the input string at
 *                char_index position, or the null character if char_index is
 *                outside the range of the string. The null character is '\0'
 */
char GetCharacter(string input, int char_index) {
  if (char_index >=0 && char_index < input.length())
    return input.at(char_index);
  else
    return '\0';
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;

  Test(Goldilocks("porridge", 2) == "This porridge is too cold", 1,
       "Goldilocks(\"porridge\", 2)");

  Test(Goldilocks("chair", 3) == "This chair is just right", 2,
       "Goldilocks(\"chair\", 3)");

  Test(Goldilocks("bed", 1) == "This bed is too hard", 3,
       "Goldilocks(\"bed\", 1)");

  Test(RockScissorPaper('r', 'S') == 1, 4, "RockScissorPaper ('r', 'S')");

  Test(RockScissorPaper('R', 'p') == 2, 5, "RockScissorPaper ('R', 'p')");

  Test(RockScissorPaper('S', 'P') == 1, 6, "RockScissorPaper ('S', 'P')");

  Test(RockScissorPaper('r', 'r') == 3, 7, "RockScissorPaper ('r', 'r')");

  Test(CharWithAsciiValueAsString('Z') == "Z 90", 8,
       "CharWithAsciiValueAsString('Z')");

  Test(CharWithAsciiValueAsString('a') == "a 97", 9,
       "CharWithAsciiValueAsString('a')");

  Test(ToLower("HELLO") == "hello", 10, "ToLower(\"HELLO\")");

  Test(ToLower("gOOdbYe") == "goodbye", 11, "ToLower(\"gOOdbYe\")");

  Test(ToUpper("hello") == "HELLO", 12, "ToUpper(\"hello\")");

  Test(ToUpper("gOOdbYe") == "GOODBYE", 13, "ToUpper(\"gOOdbYe\")");

  Test(GetCharacter("amazing", 3) == 'z', 14, "GetCharacter(\"amazing\", 3)");

  Test(GetCharacter("hooray!", 6) == '!', 15, "GetCharacter(\"hooray!\", 6)");

  Test(GetCharacter("toobig", 10) == '\0', 16, "GetCharacter(\"toobig\", 10)");

  Test(GetCharacter("toosmall", -10) == '\0', 17,
       "GetCharacter(\"toosmall\", -10)");

}
// For testing (DO NOT ALTER)
void Test(bool test, int number, string more_info) {
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << number << " " << more_info << "!\n";
}
