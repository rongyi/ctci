#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  vector<vector<string>> partition(string &s) {
    vector<vector<string>> ret;
    vector<string> cur;
    dfs(s, cur, ret, 0);
    return ret;
  }

private:
  void dfs(string &s, vector<string> cur, vector<vector<string>> &ret, int start) {
    if (start == s.length()) {
      ret.push_back(cur);
    }
    for (int i = start; i < s.length(); ++i) {
      if (isPalindrom(s, start, i)) {
        auto tmp = s.substr(start, i - start + 1);
        cur.push_back(tmp);
        dfs(s, cur, ret, i + 1);
        cur.pop_back();
      }
    }
  }


  bool isPalindrom(string &s, int start, int end) {
    while (start < end && s[start] == s[end]) {
      ++start;
      --end;
    }
    return start >= end;
  }
};

int main()
{
  Solution so;
  string test{"aab"};
  auto ret = so.partition(test);
  for (auto &v : ret) {
    for (auto &s : v) {
      cout << s << endl;
    }
    cout << "======" << endl;
  }
  return 0;
}
