#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

bool arePermutation(string &s1, string &s2) {
  const int n1 = s1.length();
  const int n2 = s2.length();
  if (n1 != n2)
    return false;
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());

  for (int i = 0; i < n1; ++i) {
    if (s1[i] != s2[i])
      return false;
  }
  return true;
}

int main()
{
  string str1 = "testest";
  string str2 = "estxest";
  if(arePermutation(str1, str2))
    cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
  else
    cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;

  str1 = "hello";
  str2 = "oellh";
  if(arePermutation(str1, str2))
    cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
  else
    cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
  return 0;
}
