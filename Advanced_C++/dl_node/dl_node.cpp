#include "dl_node.h"

DLNode::DLNode() {
  contents_ = 0;
  prev_node_ = NULL;
  next_node_ = NULL;
}

DLNode::~DLNode() {
}

void DLNode::SetContents(int contents) {
  contents_ = contents;
}

void DLNode::SetNext(DLNode* next_node) {
  next_node_ = next_node;
}

void DLNode::SetPrevious(DLNode* prev_node) {
  prev_node_ = prev_node;
}

int DLNode::GetContents() {
  return contents_;
}

DLNode* DLNode::GetNext() const {
  return next_node_;
}

DLNode* DLNode::GetPrevious() const {
  return prev_node_;
}
