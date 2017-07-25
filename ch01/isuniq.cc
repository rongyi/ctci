#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <bitset>


using std::cout;
using std::endl;
using std::string;
using std::vector;

bool is_uniq(const string &input) {
  std::unordered_set<char> aux;
  for (auto &c : input) {
    if (aux.find(c) != aux.end()) {
      return false;
    } else {
      aux.insert(c);
    }
  }
  return true;
}

bool is_uniq2(const string &input) {
  std::bitset<256> bits(0);
  for (auto &c : input) {
    if (bits.test(c) > 0)
      return false;
    bits.set(c);
  }
  return true;
}

int main() {
  vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
  for (auto word : words) {
    cout << word << string(": ") << std::boolalpha << is_uniq(word) <<endl;
  }

  for (auto word : words) {
    cout << word << string(": ") << std::boolalpha << is_uniq2(word) <<endl;
  }
  return 0;
}
