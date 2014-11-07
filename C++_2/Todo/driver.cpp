/*
* Name        : driver.cpp
* Author      : Gary Pacheco
* Description : Main file - Runs Program. Project builds a list, full of user
* inputted items and allows the user to interact with items contents
*/
// Includes
#include "todo_ui.h"

int main() {
  // Instance of TodoUI
  TodoUI ui;
  // Runs user interface
  ui.Menu();
  return 0;
}
