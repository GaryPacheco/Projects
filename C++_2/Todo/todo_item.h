 /*
 * Name        : todo_item.h
 * Author      : Gary Pacheco
 * Description : Creates items that contain description, priority, and
 * completion status
 */
// Header Guards
#ifndef PACHECO_TODO_ITEM_H
#define PACHECO_TODO_ITEM_H
// Includes
#include <iostream>
#include <string>
using std::string;
using std::ostream;

class TodoItem {
 public:
    /*
    * Default constructor.
    * Initializes description_, priority_, and completed_ to entered values
    * priority_ defaults to 1, completed_ defaults to false
    */
    TodoItem(string a_description, int a_priority = 1, bool a_complete = false);
    /*
    * Deconstructor.
    * Intentionally left blank
    */
    ~TodoItem();
    /*
    * void set_description
    * Mutator - sets description_ to inputed value
    * @param string a_description - New description_ value
    */
    void set_description(string a_description);
    /*
    * void set_priority
    * Mutator - sets priority_ to inputed value
    * @param string a_priority - New priority_ value
    */
    void set_priority(int a_priority);
    /*
    * void set_completed
    * Mutator - sets completed_ to inputed value
    * @param string a_completed - New completed_ value
    */
    void set_completed(bool a_completed);
    /*
    * string description
    * Gets the value for description_
    */
    string description();
    /*
    * string priority
    * Gets the value for priority_
    */
    int priority();
    /*
    * string completed
    * Gets the value for completed_
    */
    bool completed();
    /*
    * string ToFile
    * Combines item contents together with @ symbols
    */
    string ToFile();
    /*
    * ostream& operator<<
    * Overloads operator<< to handle printing list items neatly
    */
    friend ostream& operator<< (ostream& outs, const TodoItem& src);

 private:
    string description_;
    int priority_;
    bool completed_;
    string Scrub(string input);
};
#endif  // PACHECO_TODO_ITEM_H
