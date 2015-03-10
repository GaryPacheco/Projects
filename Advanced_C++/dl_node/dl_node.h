/*
 * Name        : dl_node.h
 * Author      : Gary Pacheco
 * Description : DLNode sets up each node in a linked list and holds their
 *               content.
 */
#ifndef PACHECO_DL_NODE_H
#define PACHECO_DL_NODE_H

#include <iostream>

class DLNode {
 public:
    /*
    * Constructor
    * Sets the default of contents_ to 0, prev_node_ to NULL, and 
    * next_node_ to NULL
    */
    DLNode();
    /*
    * Deconstructor
    * Intentionally left bank
    */
    ~DLNode();
    /*
     * void SetContents()
    * Sets the contents to the given integer
    * @param int contents - value to be stored in a node
     */
    void SetContents(int contents);
    /*
    * void SetNext()
    * Sets the next node pointer to the next node in the list
    * @param DLNode* next_node - The next node in the list
    */
    void SetNext(DLNode* next_node);
    /*
    * void SetPrevious()
    * Sets the previous node pointer to the previous node in the list
    * @param DLNode* prev_node - The previous node in the list
    */
    void SetPrevious(DLNode* prev_node);
    /*
    * int GetContents()
    * Gets the contents stored in a node
    * @return int - the contents stored in the node
    */
    int GetContents();
    /*
    * DLNode* GetNext() const
    * Gets the next node in the list
    * @return DLNode* - the pointer to the next node
    */
    DLNode* GetNext() const;
    /*
    * DLNode* GetPrevious() const
    * Gets the previous node in the list
    * @return DLNode* - the pointer to the previous node
    */
    DLNode* GetPrevious() const;

 private:
    int contents_;
    DLNode* prev_node_;
    DLNode* next_node_;
};
#endif  // PACHECO_DL_NODE_H
