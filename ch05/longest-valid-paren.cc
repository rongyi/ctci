#include <vector>
#include <iostream>
#include <string>
#include <stack>

using std::vector;
using std::cout;
using std::endl;
using std::string;
class Solution {
public:
  int longestValidParen(const std::string &s) {
    int max_len = 0;
    int last = -1;
    std::stack<int> lefts;

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        lefts.push(i);
      } else {
        if (lefts.empty()) {
          last = i;
        } else {
          lefts.pop();
          if (lefts.empty()) {
            max_len = std::max(max_len, i - last);
          } else {
            max_len = std::max(max_len, i - lefts.top());
          }
        }
      }
    }

    return max_len;
  }
};

int main()
{
  Solution so;
  string test("((()))");
  auto ret = so.longestValidParen(test);
  cout << ret << endl;

  return 0;
}
