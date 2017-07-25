#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

struct Node {
  char data;
  Node * next;
  Node( char c ) : data{ c }, next{ nullptr } { }
};

void deleteNode(Node *node) {
  if (node == nullptr || node->next == nullptr) {
    return;
  }
  Node *next = node->next;
  node->data = next->data;
  node->next = next->next;
  delete next;
}

int main()
{

  return 0;
}
