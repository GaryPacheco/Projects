/*
 * Name        : Lab_2.cpp
 * Author      : Gary Pacheco
 * Description : working with filestreams and handling file input/output
 */
 
//INCLUDES 
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ifstream;
using std::cerr;
using std::map;

//FUCTION HEADERS/PROTOTYPES
void NewCat(int argc, char *argv[]);

int main (int argc, char *argv[]) {
  NewCat(argc, argv);
  return 0;
}

//FUNCTION DEFINITIONS

void NewCat(int argc, char *argv[]) {
  ifstream fin;
  string input;
  char characters;
  if (argc == 1) {
    do { 
      cin >> input;
      cout << input << endl;
    } while (!cin.eof()); 
  } else {
    for (int i = 1; i < argc; i++) {
      fin.open(argv[i]);
      if (fin.fail()) {
        cerr << "Argument did not match file name.\n";
        exit(1);
      }
      characters = fin.get();
      while(!fin.eof()) {
        cout << characters;
        characters = fin.get();
      }
    fin.close();
    }
  }
}