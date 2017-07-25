#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

string urlify(const string &input) {
  std::stringstream ss;
  for (auto &c : input) {
    if (c == ' ') {
      ss << "%20";
    } else {
      ss << c;
    }
  }

  return ss.str();
}

void urlify(char *str, int len) {
  int space_count = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == ' ') {
      ++space_count;
    }
  }

  int new_len = len + 2 * space_count;
  for (int i = new_len - 1, j = len - 1; j>= 0; --j) {
    if (str[j] != ' ') {
      str[i--] = str[j];
    } else {
      str[i--] = '0';
      str[i--] = '2';
      str[i--] = '%';
    }
  }
}


int main()
{
  char str[] = "Mr John Smith    ";                       //String with extended length ( true length + 2* spaces)
  std::cout << "Actual string   : " << str << std::endl;
  urlify(str, 13);                                        //Length of "Mr John Smith" = 13
  std::cout << "URLified string : " << str << std::endl;
  return 0;
}
