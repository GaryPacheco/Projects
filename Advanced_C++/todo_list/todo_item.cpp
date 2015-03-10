#include "todo_item.h"
#include <iomanip>
#include <iostream>
#include <sstream>
using std::stringstream;
using std::string;
using std::endl;
using std::cout;

TodoItem::TodoItem(string a_description, int a_priority, bool a_completed)
:description_(a_description), priority_(a_priority), completed_(a_completed) {
}

TodoItem::~TodoItem() {
}

void TodoItem::set_description(string a_description) {
  description_ = a_description;
}

void TodoItem::set_priority(int a_priority) {
  if ( a_priority <= 0 || a_priority > 5 )
    priority_ = 5;
  else
    priority_ = a_priority;
}

void TodoItem::set_completed(bool a_completed) {
  completed_ = a_completed;
}

string TodoItem::description() {
  return description_;
}

int TodoItem::priority() {
  return priority_;
}

bool TodoItem::completed() {
  return completed_;
}

string TodoItem::ToFile() {
  stringstream ss;
  string a_string = "";
  ss << Scrub(description_) << "@" << priority_ << "@" << completed_;
  a_string = ss.str();
  return a_string;
}

string TodoItem::Scrub(string input) {
  for (unsigned int i = 0; i < input.length(); i++) {
    if ( input[i] == '@' ) {
      input[i] = '#';
    }
  }
  return input;
}

ostream& operator<< (ostream& outs, const TodoItem& src) {
  outs << "\tDescription:\t" << src.description_ << endl;
  outs << "\tPriority:\t" << src.priority_ << endl;
  outs << "\tCompleted:\t";
  if ( src.completed_ == true )
    outs << "True" << endl;
  else
    outs << "False" << endl;
  return outs;
}
