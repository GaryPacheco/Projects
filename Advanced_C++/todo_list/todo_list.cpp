#include "todo_list.h"

TodoList::TodoList()
:list_capacity_(25), list_size_(0) {
  items = new TodoItem*[list_capacity_];
  for (int i = 0; i < list_capacity_; i++)
    items[i] = NULL;
}

TodoList::~TodoList() {
  for (int i = 0; i < list_capacity_; i++) {
    if ( items[i] != NULL )
      delete items[i];
  }
  delete [] items;
}

void TodoList::AddItem(TodoItem* an_item) {
  if (list_size_ < list_capacity_) {
    items[list_size_++] = an_item;
  } else {
    IncCap();
    items[list_size_++] = an_item;
  }
}

void TodoList::DeleteItem(int to_change) {
  for (int i = 0; i < list_capacity_; i++) {
    if (to_change - 1 == i) {
      delete items[i];
      items[i] = NULL;
      Compact(i);
    }
  }
}

TodoItem* TodoList::GetItem(int item_index) {
  return items[item_index - 1];
}

int TodoList::GetSize() {
  return list_size_;
}

int TodoList::GetCapacity() {
  return list_capacity_;
}

void TodoList::Sort() {
  TodoItem** temp = new TodoItem*[list_capacity_];
  for (int i = 0; i < list_size_; i++) {
    for (int j = i + 1; j < list_size_; j++) {
      if ( items[j]->priority() < items[i]->priority() ) {
        temp[i] = items[i];
        items[i] = items[j];
        items[j] = temp[i];
      }
    }
  }
}

void TodoList::IncCap() {
  list_capacity_ += 10;
  TodoItem** new_item = new TodoItem* [list_capacity_];
  for (int i = 0; i < list_size_; i++)
    new_item[i] = items[i];
  delete [] items;
  items = new_item;
}

void TodoList::Compact(int index) {
  for (int i = index; i < list_size_ - 1; i++) {
    items[i] = items[i + 1];
  }
  list_size_ = list_size_ - 1;
}

void TodoList::DeleteAll() {
  if (list_size_ > 0) {
    for (int i = 0; i < list_capacity_; i++) {
      delete items[i];
      items[i] = NULL;
    }
    list_size_ = 0;
  } else {
    cout << "No items to delete!";
  }
}

string TodoList::ToFile() {
  stringstream ss;
  string a_string = "";
  for (int i = 0; i < list_size_; i++) {
    ss << items[i]->ToFile() << "\n";
  }
  a_string = ss.str();
  return a_string;
}

ostream& operator<< (ostream& outs, const TodoList& src) {
  for (int i = 0; i < src.list_size_; i++) {
    outs << "(" << i << ") " << *src.items[i] << "\n";
  }
  return outs;
}

// EXTRA CREDIT (search keyword & delete keyword)
void TodoList::HasKeyword(string search_item) {
  string temp1 = search_item;
  string temp2;
  char input;
  for (int i = 0; i < list_size_; i++) {
    temp2 = items[i]->description();
    for (unsigned int j = 0; j < temp2.length(); j++)
      temp2[j] = tolower(temp2[j]);
    for (unsigned int k = 0; k < search_item.length(); k++)
      temp1[k] = tolower(search_item[k]);
    if ( temp2.find(temp1) != string::npos ) {
      cout << "Name: Priority: Completion:\n";
      cout << items[i]->description() << " " << "("
           << items[i]->priority() << ") "
           << items[i]->completed() << "\n";
      cout << "\nWould you like to delete this item?(y,n) ";
      input = reader.readChar("YyNn");
      if (tolower(input) == 'y') {
        delete items[i];
        items[i] = NULL;
        Compact(i);
      }
    } else {
      cout << "Error: Item Not Found. Please Check Spelling.\n";
    }
  }
}

// EXTRA CREDIT (Deletes Complete Items)
void TodoList::DeleteComplete() {
  for (int i = 0; i < list_size_; i++) {
    if ( items[i]->completed() == true ) {
        delete items[i];
        items[i] = NULL;
        Compact(i);
        i = 0;
    }
  }
}
