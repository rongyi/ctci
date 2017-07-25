#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::string;


struct Node {
  int data_;
  Node * next_;
};

void removeDuplicates(Node *head) {
  if (head == nullptr || (head && (head->next_ == nullptr)))
    return;

  std::unordered_map<int, int> cm;
  Node *prev = head;
  Node *cur = head->next_;

  cm[head->data_] = 1;

  while (cur != nullptr) {
    while (cur && cm.find(cur->data_) != cm.end()) {
      cur = cur->next_;
    }
    prev->next_ = cur;
    prev = cur;
    // put distint node to map
    if (cur) {
      cm[cur->data_] = 1;
      cur = cur->next_;
    }
  }
}

int main()
{

  return 0;
}
