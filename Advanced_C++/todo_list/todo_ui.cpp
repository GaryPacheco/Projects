#include "todo_ui.h"

TodoUI::TodoUI() {
  list = new TodoList;
}

TodoUI::~TodoUI() {
  delete [] list;
}

void TodoUI::Menu() {
  bool quit = false;
  int choice = 0;
  string input = "";
  int priority = 0;
  bool completed = false;
  while (quit == false) {
    quit = false;
    choice = 0;
    cout << "\nPlease select an option: \n";
    cout << "(1) Create New Item\n";
    cout << "(2) Edit Item\n";
    cout << "(3) Delete An Item\n";
    cout << "(4) View All Items\n";
    cout << "(5) Veiw Specific Item\n";
    cout << "(6) Delete All Items\n";
    cout << "(7) Search/Delete by Keyword\n";
    cout << "(8) Delete Completed Items\n";
    cout << "(0) Quit Program\n";
    cout << "Your Choice: ";
    choice = reader.readInt(0, 8);

    switch (choice) {
      case 1:
        // Add Items
        cout << "\nInsert a description: \n";
        input = reader.readString();
        cout << "Insert the priority(1-5): \n";
        priority = reader.readInt(1, 5);
        cout << "Is list item completed?(true,false)\n";
        completed = reader.readBool();
        list->AddItem(new TodoItem(input, priority, completed));
        list->Sort();
      break;
      case 2:
        // Edit Items
        quit = false;
        if (list->GetSize() != 0) {
          print();
          cout << "Which item would you like to edit?\n";
          choice = reader.readInt(0, list->GetSize());
          for (int i = 0; i < list->GetSize(); i++) {
            if (choice == i) {
              while (quit == false) {
                cout << "\n[1] Change Name" << endl;
                cout << "[2] Change Priority" << endl;
                cout << "[3] Change Completion Status" << endl;
                cout << "[0] Done Editing" << endl;
                cout << "Your choice: ";
                switch (reader.readInt(0, 3)) {
                  case 1:
                    cout << "Enter new item name: ";
                    input = reader.readString();
                    list->GetItem(choice)->set_description(input);
                  break;
                  case 2:
                    cout << "Enter new priority(1-5): ";
                    priority = reader.readInt(0, 5);
                    list->GetItem(choice)->set_priority(priority);
                  break;
                  case 3:
                    cout << "Is task completed? (true,false) ";
                    completed = reader.readBool();
                    list->GetItem(choice)->set_completed(completed);
                  break;
                  case 0:
                    quit = true;
                  break;
                }
              }
            }
          }
        }
        quit = false;
      break;
      case 3:
        // Delete Items
        print();
        if (list->GetSize() > 0) {
          cout << "\nWhich list item would you like to delete: ";
          choice = reader.readInt(0, list->GetSize());
          list->DeleteItem(choice);
        }
      break;
      case 4:
        // View List
        print();
      break;
      case 5:
        // View specific item
        list->Sort();
        if ( list->GetSize() == 0 ) {
          cout << "\nNo items in list!\n";
        } else {
          cout << "\n\tName: Priority: Completion:" << endl;
          for ( int i = 1; i < list->GetSize() + 1; i++ ) {
            cout << "[" << i << "]\t"
                 << list->GetItem(i)->description() << "\t"
                 << "(" << list->GetItem(i)->priority() << ") \t";
            if ( list->GetItem(i)->completed() == 1)
              cout << "True" << endl;
            else
              cout << "False" << endl;
          }
        }
        cout << "What item number would you like to select? ";
        choice = reader.readInt(1, list->GetSize());
        for (int i = 1; i < list->GetSize() + 1; i++) {
          if (choice == i) {
            cout << "\nName: Priority: Completion:" << endl;
            cout << list->GetItem(i)->description() << "\t"
            << "(" << list->GetItem(i)->priority() << ") \t";
            if ( list->GetItem(i)->completed() == 1)
              cout << "True" << endl;
            else
              cout << "False" << endl;
          }
        }
      break;
      case 6:
        // Delete List
        list->DeleteAll();
      break;
      case 7:
        // Search For Keywords
        cout << "Please enter items name you are looking for: \n";
        input = reader.readString();
        list->HasKeyword(input);
      break;
      case 8:
        // Delete Completed Items
        list->DeleteComplete();
      break;
      case 0:
        // Exit
        list->~TodoList();
        quit = true;
      break;
    }
  }
}

void TodoUI::print() {
  list->Sort();
  if ( list->GetSize() == 0 ) {
    cout << "\nNo items in list!\n";
  } else {
    if ( list->GetSize() == 0 ) {
      cout << "\nNo items in list!\n";
    } else {
      cout << "\n\tName: Priority: Completion:" << endl;
      for ( int i = 1; i < list->GetSize() + 1; i++ ) {
        cout << "[" << i << "]\t"
             << list->GetItem(i)->description() << "\t"
             << "(" << list->GetItem(i)->priority() << ") \t";
        if ( list->GetItem(i)->completed() == 1)
          cout << "True" << endl;
        else
          cout << "False" << endl;
      }
    }
  }
}
