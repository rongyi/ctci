#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

bool oneAway(std::string s1, std::string s2) {
  // assume s1 is the short one
  if (s1.size() > s2.size()) {
    std::swap(s1, s2);
  }

  const int len_delta = s2.size() - s1.size();
  if (len_delta > 2)
    return false;
  if (len_delta == 1) {
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        return s1.substr(i) == s2.substr(i + 1);
      }
    }
  } else if (len_delta == 0) {
    int diff_count = 0;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i]) {
        diff_count++;
      }
    }
    return diff_count == 1;
  }
  return true;
}

void translate( bool result, const std::string str1, const std::string str2 )
{
  if (result == true ) {
    std::cout << str1 << " and " << str2 << " are one edit away\n";
  } else {
    std::cout << str1 << " and " << str2 << " are not one edit away\n";
  }
}

int main()
{
  translate(oneAway("pale", "ple"), "pale", "ple" );
  translate(oneAway("pales", "pale"), "pales", "pale" );
  translate(oneAway("pale", "pales"), "pale", "pales" );
  translate(oneAway("pale", "bale"), "pale", "bale" );
  translate(oneAway("pale", "bake"), "pale", "bake" );
  return 0;
}
