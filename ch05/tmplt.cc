#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <list>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main()
{
  int data[]{1, 3, 4, 5, 6, 7};
  auto iter = std::begin(data);
  std::advance(iter, 3);
  cout << "Fourth element is " << *iter << endl;
  cout << std::distance(std::begin(data), std::end(data)) << endl;
  cout << sizeof(data) / sizeof(data[0]) << endl;
  std::multiset<int> ms;
  ms.insert(1);
  ms.insert(2);
  ms.insert(1);
  ms.insert(9);
  cout << "==================" << endl;
  cout << *ms.begin() << endl;
  cout << *(std::prev(ms.end())) << endl;

  cout << "=====list====" << endl;
  std::list<int> test_list;
  test_list.push_back(1);
  test_list.push_front(2);
  for (auto iter = test_list.begin(); iter != test_list.end(); ++iter) {
    cout << *iter << endl;
  }
  test_list.splice(test_list.begin(), test_list, std::next(test_list.begin()));
  for (auto iter = test_list.begin(); iter != test_list.end(); ++iter) {
    cout << *iter << endl;
  }
  return 0;
}
