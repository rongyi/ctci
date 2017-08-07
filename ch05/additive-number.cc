#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;
class Solution {
public:
  bool isAdditiveNumber(string num) {
    for (int i = 1; i <= num.length() / 2; ++i) {
      if (num[0] == '0' && i > 1)
        continue;
      for (int j = i + 1; i < num.length(); ++j) {
        if (num[i] == '0' && j - i > 1)
          continue;
        if (dfs(num, 0, i, j))
          return true;
      }
    }
    return false;
  }
private:
  bool dfs(string num, int i, int j, int k) {
    auto num1 = std::stol(num.substr(i, j - i));
    auto num2 = std::stol(num.substr(j, k - j));
    string addtion = std::to_string(num1 + num2);

    if (!(num.substr(k, addtion.size()) == addtion))
      return false;
    if (k + addtion.length() == num.length())
      return true;

    return dfs(num, j, k, k + addtion.length());
  }

};


int main()
{
  Solution so;
  string test("199100199");
  auto ret = so.isAdditiveNumber(test);
  cout << ret << endl;
  return 0;
}
