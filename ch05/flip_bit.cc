#include <vector>
#include <iostream>
#include <string>
#include <limits>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int flipToWin(unsigned i) {
  int ret = 1;
  int lenLeft = 0;
  int lenRight = 0;

  while (i) {
    if (i & 1) {
      ++lenRight;
    } else {
      lenLeft = lenRight;
      lenRight = 0;
    }
    i >>= 1;
    ret = std::max(ret, lenRight + lenLeft + 1);
  }

  return std::min(ret, std::numeric_limits<unsigned>::digits);
}


int main() {


  for (auto testValue : {
      0b11011101111U
        ,  0b110111001111U
        , 0b1100111001111U
        , 0U
        , ~0U
        })
    std::cout << ": " << flipToWin(testValue) << std::endl;


  return 0;
}
