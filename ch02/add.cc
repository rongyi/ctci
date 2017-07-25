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
  Node ( int d ) : data{ d }, next{ nullptr } { }
};

Node *add(Node *list1, Node *list2) {
  if (list1 == nullptr)
    return list2;
  if (list2 == nullptr)
    return list1;

  Node *ret = nullptr;
  Node *retTail = nullptr;

  int value = 0, carry = 0;

  while (list1 || list2) {
    value = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
    if (value > 9) {
      carry = 1;
      value = value % 10;
    } else {
      carry = 0;
    }
    Node *tmp = new Node(value);
    if (ret == nullptr) {
      ret = tmp;
    } else {
      retTail->next = tmp;
    }
    retTail = tmp;

    if (list1) {
      list1 = list1->next;
    }
    if (list2) {
      list2 = list2->next;
    }
  }
  if (carry > 0) {
    retTail->next = new Node(carry);
  }

  return ret;
}
int main()
{

  return 0;
}
