#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

void helper_transpose(vector<vector<int>> &matrix) {
  const int m = matrix.size();
  const int n = matrix[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
}

void helper_reverse(vector<int> &row) {
  for (size_t i = 0; i < row.size() / 2; ++i) {
    std::swap(row[i], row[row.size() - i - 1]);
  }
}

void roate(vector<vector<int>> &matrix) {
  helper_transpose(matrix);
  for (size_t i = 0; i < matrix.size(); ++i) {
    helper_reverse(matrix[i]);
  }
}


int main()
{

  return 0;
}
