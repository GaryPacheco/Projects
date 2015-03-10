/*
 * Name        : dl_list.h
 * Author      : Gary Pacheco
 * Description : DLList Class handles the functions that manipulate the nodes
 *               within the double linked list.
 */
#ifndef PACHECO_DL_LIST_H
#define PACHECO_DL_LIST_H

#include "dl_node.h"
#include <iostream>
#include <sstream>
using std::stringstream;
using std::cout;
using std::cerr;
using std::string;

class DLList {
 public:
    /*
    * Constructor
    * Sets the default of head_ to NULL, tail_ to NULL, and size to 0
    */
    DLList();
    /*
    * Deconstructor
    * Calls the Clear() function to remove nodes and frees memory
    */
    ~DLList();
    /*
    * int GetSize() const
    *Gets the size of the list from variable size_
    * @return int - size of the linked list
    */
    int GetSize() const;
    /*
    * void PushFront()
    * Adds the given value to the front of the linked list.
    * @param int value - value to be added to list
    */
    void PushFront(int value);
    /*
    * void PushBack()
    * Adds the given value to the back of the linked list.
    * @param int value - value to be added to list
    */
    void PushBack(int value);
    /*
    * int GetFront() const
    * Gets the value stored in the front of the linked list
    *@return int - value store in the head_ node
    */
    int GetFront() const;
    /*
    * int GetBack() const
    * Gets the value stored in the front of the linked list
    * @return int - value store in the tail_ node
    */
    int GetBack() const;
    /*
    * void PopFront()
    * Removes the node at the front of the linked list and adjust the list size
    */
    void PopFront();
    /*
    * void PopFront()
    * Removes the node at the back of the linked list and adjusts the list size
    */
    void PopBack();
    /*
    * void RemoveFirst()
    * Removes the first occurence of the given value
    * @param int value - value to be found in list
    */
    void RemoveFirst(int value);
    /*
    * void RemoveAll()
    * Removes the given value throughout the list
    * @param int value - value to be found in list
    */
    void RemoveAll(int value);
    /*
    * bool Exists()
    * Searches the list for the given value and returns true or false if value
    * was found within the list
    * @param int value - value to be found in list
    * @return bool - true if value was found, false if value was not found
    */
    bool Exists(int value);
    /*
    * void Clear()
    * Clears the list of all nodes and frees memory
    */
    void Clear();
    /*
    * string ToStringForwards()
    * Combines all the value in the list seperated by a ','. Starts at head_ and
    * ends at tail_
    * @return string - the list of combined values
    */
    string ToStringForwards();
    /*
    * string ToStringForwards()
    * Combines all the value in the list seperated by a ','. Starts at tail_ and
    * ends at head_
    * @return string - the list of combined values
    */
    string ToStringBackwards();

 private:
    int size_;
    DLNode* head_;
    DLNode* tail_;
};
#endif  // PACHECO_DL_LIST_H
