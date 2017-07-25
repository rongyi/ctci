#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

Node *partition(Node *listhead, int x) {
  Node *head = nullptr;
  Node *headInitial = nullptr;
  Node *tail = nullptr;
  Node *tailInitial = nullptr;

  Node *cur = listhead;
  while (cur != nullptr) {
    Node *next = cur->next;
    if (cur->next < x) {
      if (head == nullptr) {
        head = cur;
        headInitial = head;
      }
      head->next = cur;
      head = cur;
    } else {
      if (tail == nullptr) {
        tail = cur;
        tailInitial = tail;
      }
      tail->next = cur;
      tail = cur;
    }
    cur = next;
  }
  head->next = tailInitial;
  tail->next = nullptr;
  return headInitial;
}

int main()
{

  return 0;
}
