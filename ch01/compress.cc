#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

string compress(string input) {
  size_t len = input.length();
  if (len < 2)
    return input;
  string out{""};
  int cur_count = 1;
  for (size_t i = 1; i < len; ++i) {
    if (input[i - 1] == input[i]) {
      ++cur_count;
    } else {
      out += input[i - 1];
      out += std::to_string(cur_count);
      cur_count = 1;
    }
    if (out.length() >= len)
      return input;
  }
  out += input[len - 1];
  out += std::to_string(cur_count);

  if (out.length() >= len)
    return input;
  return out;
}

int main()
{
  std::string str("aabccccaaa"), out;
  out = compress(str);
  if (str.compare(out)) {
    std::cout << str << " can be compressed to " << out << std::endl;
  } else {
    std::cout << str << " can not be compressed\n";
  }
  return 0;
}
