/*
 * Name        : todo_list.h
 * Author      : Gary Pacheco
 * Description : Creates a list that contains all items and handles
 * list functionality
 */
// Header Guards
#ifndef PACHECO_TODO_LIST_H
#define PACHECO_TODO_LIST_H
// Includes
#include "todo_item.h"
#include "CinReader.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using std::ostream;
using std::stringstream;
using std::cout;
using std::tolower;

class TodoList {
 public:
    /*
    * Default constructor.
    * Initializes list_capacity_ to 25, iniializes list_size_ to 0
    * Creates new instance of list
    */
    TodoList();
    /*
    * Deconstructor.
    * Deletes all items in list and deletes list.
    */
    ~TodoList();
    /*
    * void AddItem
    * Adds an item to the list
    * @param TodoItem* an_item - new value for item in list
    */
    void AddItem(TodoItem* an_item);
    /*
    * void DeleteItem
    * Deletes an item for the list
    * @param int to_change - index for the item to be deleted
    */
    void DeleteItem(int to_change);
    /*
    * TodoItem* GetItem
    * Retrieves item details from the list
    * @param int item_index - index for the item to be retrieved
    */
    TodoItem* GetItem(int item_index);
    /*
    * int GetSize
    * Gets the size of the list
    */
    int GetSize();
    /*
    * int GetCapcity
    * Gets the capacity of the list
    */
    int GetCapacity();
    /*
    * void Sort
    * Sorts items in the list
    */
    void Sort();
    /*
    * void DeleteAll
    * Deletes all items in the list
    */
    void DeleteAll();
    /*
    * string ToFile
    * Prints the list neatly
    */
    string ToFile();
    /*
    * ostream& operator<<
    * Overloads operator<< to handle printing list items neatly
    */
    friend ostream& operator<<(ostream& outs, const TodoList& src);
    /*
    * void HasKeyword -- Extra Credit (search keyword & delete keyword)
    * Searches list for items that match users input
    * @param string search_item - Keyword user is looking for
    */
    void HasKeyword(string search_item);
    /*
    * void DeleteComplete -- Extra Credit
    * Deletes all completed items in list
    */
    void DeleteComplete();

 private:
    TodoItem** items;
    int list_capacity_;
    int list_size_;
    void IncCap();
    void Compact(int index);
    CinReader reader;
};
#endif  // PACHECO_TODO_LIST_H
