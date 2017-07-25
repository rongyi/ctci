#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

void clearRow(vector<vector<int>> &matrix, int row) {
  const int n = matrix[0].size();
  for (int i = 0; i < n; ++i) {
    matrix[row][i] = 0;
  }
}

void clearCol(vector<vector<int>> &matrix, int col) {
  const int m = matrix.size();
  for (int i = 0; i < m; ++i) {
    matrix[i][col] = 0;
  }
}

void clearMatrix(vector<vector<int>> &matrix) {
  bool first_row = false;
  const int m = matrix.size();
  const int n = matrix[0].size();
  for (int i = 0; i < n; ++i) {
    if (matrix[0][i] == 0) {
      first_row = true;
      break;
    }
  }

  for (int i = 0; i < m; ++i) {
    bool shouldClear = false;
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        shouldClear = true;
      }
    }
    if (shouldClear) {
      clearRow(matrix, i);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (matrix[0][i] == 0) {
      clearCol(matrix, i);
    }
  }
  if (first_row)
    clearRow(matrix, 0);
}

int main()
{

  return 0;
}
