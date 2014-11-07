#include "natural_list.h"

NaturalList::NaturalList(unsigned int capacity) {
  list_ = new unsigned int[capacity];
  capacity_ = capacity;
  for (unsigned int i = 0; i < capacity_; i++)
    list_[i] = NULL;
  size_ = 0;
}

NaturalList::~NaturalList() {
  delete[] list_;
}

bool NaturalList::Add(unsigned int value) {
  if (value > 0) {
    if (size_ < capacity_) {
      list_[size_] = value;
      size_++;
      return true;
    }
  }
  return false;
}

unsigned int NaturalList::GetNumber(unsigned int index) {
  if (index < size_) {
    return list_[index];
  }
  return 0;
}

string NaturalList::ToString() {
  stringstream ss;
  string the_string;
  if (size_ > 0) {
    for (unsigned int i = 0; i < size_; i++) {
      ss << list_[i];
	  if (i != size_ - 1)
	    ss << ", ";
    }
  } else {
   ss << "List Empty";
  }
  the_string = ss.str();
  return the_string;
}

unsigned int NaturalList::GetSize() {
  return size_;
}

unsigned int NaturalList::GetCapacity() {
  return capacity_;
}

unsigned int NaturalList::Sum() {
  unsigned int sum = 0;
  if ( size_ != 0 ) {
    for (unsigned int i = 0; i < size_; i++)
      sum += list_[i];
	return sum;
  }
  return 0;
}

double NaturalList::Average() {
  double avg = 0;
  if ( size_ != 0 ) {
    for (unsigned int i = 0; i < size_; i++)
	  avg += list_[i];
	return avg/size_;
  }
  return 0;
}

void NaturalList::Clear(unsigned int new_size) {
  delete[] list_;
  list_ = new unsigned int[new_size];
  capacity_ = new_size;
  size_ = 0;
}
