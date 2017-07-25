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
  Node(int d) : data{ d }, next{ nullptr } { }
};

Node *kthToLast(Node *head, int k) {
  if (head == nullptr)
    return head;

  Node *p1 = head;
  Node *p2 = head;

  int i = 0;
  while (i < k && p1) {
    p1 = p1->next;
    ++i;
  }

  if (i < k) {
    return nullptr;
  }

  while (p1 != nullptr) {
    p1 = p1->next;
    p2 = p2->next;
  }

  return p2;
}


int main()
{

  return 0;
}
