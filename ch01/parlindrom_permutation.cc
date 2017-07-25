#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cctype>

using std::vector;
using std::cout;
using std::endl;
using std::string;

bool isPermutationOfPallindrome(const string &input) {
  auto idx = [](char c) -> int {
    if (std::islower(c))
      return c - 'a';
    else if (std::isupper(c))
      return c - 'A';
    // ignore special char
    return -1;
  };

  std::unordered_map<int, int> aux;
  for (auto &c : input) {
    int key = idx(c);
    if (key == -1)
      continue;
    if (aux.find(key) == aux.end()) {
      aux[key] = 1;
    } else {
      ++aux[key];
    }
  }

  bool has_odd = false;
  for (auto iter = aux.begin(); iter != aux.end(); iter++) {
    if (iter->second & 0x1 && has_odd) {
      return false;
    } else if (iter->second & 0x1 && !has_odd) {
      has_odd = true;
    }
  }

  return true;
}

int toggle(int bit, int index) {
  int mask = 1 << index;
  if ((bit & mask) == 0) {
    bit |= mask;
  } else {
    bit &= ~mask;
  }

  return bit;
}

bool isPermutationOfPallindrome2(const string &input) {
  int bit = 0;
  int id = 0;
  auto idx = [](char c) -> int {
    if (std::islower(c))
      return c - 'a';
    else if (std::isupper(c))
      return c - 'A';
    // ignore special char
    return -1;
  };

  for (auto &c : input) {
    id = idx(c);
    if (id < 0)
      continue;
    bit = toggle(bit, id);
  }

  return bit == 0 || ((bit & (bit - 1)) == 0);
}

int main()
{

  std::string str("Tact Coa");
  std::cout << "Does \"" << str << "\"  has a string whose permutation is a pallindrome? "
           << "( 1 for true, 0 for false ) : " << std::endl;
  std::cout << "Approach 1:" << isPermutationOfPallindrome(str) << std::endl;
  std::cout << "Approach 1:" << isPermutationOfPallindrome2(str) << std::endl;
  return 0;
}
