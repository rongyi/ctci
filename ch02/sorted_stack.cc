#include <vector>
#include <iostream>
#include <string>
#include <stack>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class SortedStack {
public:
  SortedStack() : is_sorted_(false) {

  }
  void push(int i) {
    s_.push(i);
    is_sorted_ = false;
  }
  void pop() {
    sort();
    s_.pop();
  }
  int top() {
    sort();
    return s_.top();
  }
  bool empty() {
    return s_.empty();
  }
private:
  void sort() {
    if (is_sorted_)
      return;
    std::stack<int> helper;
    while (!s_.empty()) {
      int i = s_.top();
      s_.pop();
      while (!helper.empty() && i < helper.top()) {
        s_.push(helper.top());
        helper.pop();
      }
      helper.push(i);
    }
    while (!helper.empty()) {
      s_.push(helper.top());
      helper.pop();
    }
    is_sorted_ = true;
  }


private:
  std::stack<int> s_;
  bool is_sorted_;
};


int main()
{
  SortedStack stack;
  for (auto v : {5, 10, 4, 9, 3, 3, 8, 1, 2, 2, 7, 6}) {
    stack.push(v);
    std::cout << "Pushed value: " << v << std::endl;
  }

  std::cout << std::endl;

  while (!stack.empty()) {
    auto v = stack.top();
    stack.pop();
    std::cout << "Popped value: " << v << std::endl;
  }
  return 0;
}
