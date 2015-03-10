#include "dl_list.h"

DLList::DLList() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

DLList::~DLList() {
  Clear();
}

int DLList::GetSize() const {
  return size_;
}

void DLList::PushFront(int value) {
  DLNode* temp = new DLNode();
  temp->SetContents(value);
  temp->SetNext(head_);
  temp->SetPrevious(NULL);
  if ( head_ != NULL ) {
    head_->SetPrevious(temp);
    head_ = temp;
    size_++;
  } else {
    head_ = temp;
    size_++;
  }
  if ( size_ == 1 ) {
    tail_ = head_;
  }
}

void DLList::PushBack(int value) {
  if ( head_ == NULL ) {
    PushFront(value);
  } else {
    DLNode* temp = new DLNode();
    temp->SetContents(value);
    tail_->SetNext(temp);
    temp->SetPrevious(tail_);
    tail_ = temp;
    size_++;
  }
}

int DLList::GetFront() const {
  if ( head_ == NULL ) {
    cerr << "List Empty";
    return 0;
  } else {
    return head_->GetContents();
  }
}

int DLList::GetBack() const {
  if ( head_ == NULL ) {
    cerr << "List Empty";
    return 0;
  } else {
    return tail_->GetContents();
  }
}

void DLList::PopFront() {
  if ( head_ == NULL ) {
    tail_ = head_;
    cerr << "List Empty";
  } else {
    DLNode* temp = head_;
    if ( head_->GetNext() != NULL ) {
      head_ = head_->GetNext();
      head_->SetPrevious(NULL);
      delete temp;
      size_--;
    } else {
      head_ = NULL;
      tail_ = NULL;
      delete temp;
      size_--;
    }
  }
}

void DLList::PopBack() {
  if ( tail_ == NULL ) {
    cerr << "List Empty";
  } else if ( tail_ == head_ ) {
    PopFront();
  } else {
    DLNode* temp = tail_;
    tail_ = tail_->GetPrevious();
    tail_->SetNext(NULL);
    delete temp;
    size_--;
  }
}

void DLList::RemoveFirst(int value) {
  DLNode *iterator = head_;
  DLNode *trailer = head_;
  DLNode *keeper;
  while ( iterator != NULL && iterator->GetContents() != value ) {
    trailer = iterator;
    iterator = iterator->GetNext();
  }
  if (iterator == NULL) {
    cerr << "Not Found";
  } else if ( iterator == head_ ) {
    PopFront();
  } else if ( iterator == tail_ ) {
    PopBack();
  } else if ( iterator->GetContents() == value ) {
    trailer->SetNext(iterator->GetNext());
    keeper = iterator->GetNext();
    keeper->SetPrevious(trailer);
    delete iterator;
    size_--;
  }
}

void DLList::RemoveAll(int value) {
  DLNode *iterator = head_;
  DLNode *trailer = head_;
  DLNode *keeper;
  bool not_found = false;
  if ( head_ == NULL ) {
    cerr << "Not Found";
  } else if (head_->GetContents() == value) {
    PopFront();
    RemoveAll(value);
  } else if (tail_->GetContents() == value) {
    PopBack();
    RemoveAll(value);
  } else {
    while ( iterator != NULL ) {
      if ( iterator->GetContents() == value ) {
        trailer->SetNext(iterator->GetNext());
        keeper = iterator->GetNext();
        keeper->SetPrevious(trailer);
        delete iterator;
        size_--;
        not_found = true;
      }
      trailer = iterator;
      iterator = iterator->GetNext();
    }
    if ( not_found == false ) {
      cerr << "Not Found";
    }
  }
}

bool DLList::Exists(int value) {
  if ( head_ != NULL ) {
    DLNode *iterator = head_;
    while ( iterator != NULL ) {
      if ( iterator->GetContents() == value ) {
        return true;
      }
      iterator = iterator->GetNext();
    }
  }
  return false;
}

void DLList::Clear() {
  while ( head_ != tail_ ) {
    PopBack();
  }
  delete head_;
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

string DLList::ToStringForwards() {
  stringstream ss;
  string a_string = "";
  if ( head_ != NULL ) {
    DLNode *iterator = head_;
    while ( iterator != NULL ) {
      ss << iterator->GetContents();
      if ( iterator->GetNext() != NULL )
        ss << ", ";
      iterator = iterator->GetNext();
    }
    a_string = ss.str();
    return a_string;
  } else {
    cerr << "List Empty";
    return "";
  }
}

string DLList::ToStringBackwards() {
  stringstream ss;
  string a_string = "";
  if ( tail_ != NULL ) {
    DLNode *iterator = tail_;
    while ( iterator != NULL ) {
      ss << iterator->GetContents();
      if ( iterator->GetPrevious() != NULL )
        ss << ", ";
      iterator = iterator->GetPrevious();
    }
    a_string = ss.str();
    return a_string;
  } else {
    cerr << "List Empty";
    return "";
  }
}
