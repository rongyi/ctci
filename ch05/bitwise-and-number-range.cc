#include <vector>
#include <iostream>
#include <string>
#include <limits>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  int rangeBitwisedAnd(int m , int n) {
    int mask = std::numeric_limits<int>::max();
    while ((m & mask) != (n & mask)) {
      mask = mask << 1;
    }
    return m & mask;
  }
};

int main()
{
  int m = 26;
  int n = 30;
  cout << Solution().rangeBitwisedAnd(m, n) << endl;
  return 0;
}
