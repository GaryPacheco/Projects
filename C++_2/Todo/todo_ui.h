 /*
 * Name        : todo_ui.h
 * Author      : Gary Pacheco
 * Description : User interface for todo list
 * EX. Adding, removing, editing, and deleting items
 */
// Header Guard
#ifndef PACHECO_TODO_UI_H
#define PACHECO_TODO_UI_H
// Includes
#include "todo_list.h"
#include "CinReader.h"
#include <iostream>
using std::cout;
using std::cin;
using std::string;

class TodoUI {
 public:
    /*
    * Default constructor.
    */
    TodoUI();
    /*
    * Deconstructor.
    * Intentionally left blank
    */
    ~TodoUI();
    /*
    * void Menu
    * Handles interfacing between user and list
    */
    void Menu();
    /*
    * void print
    * Quick function to print items in the list neatly
    */
    void print();

 private:
    TodoList* list;
    CinReader reader;
};
#endif  // PACHECO_TODO_UI_H
