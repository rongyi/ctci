#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

bool is_rotation(string s1, string s2) {
  size_t len1 = s1.length();
  size_t len2 = s2.length();
  if (len1 == 0 || len1 != len2)
    return false;
  string concats1 = s1 + s1;
  if (concats1.find(s2) != string::npos) {
    return true;
  }
  return false;
}

int main()
{

  return 0;
}
