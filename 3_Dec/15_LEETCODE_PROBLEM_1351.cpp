class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    int i = 0;
    int j = col - 1;
    int count = 0;
    while (i < row && j >= 0) {
      if (grid[i][j] < 0) {
        count += (row - i);
        j--;
      } else {
        i++;
      }
    }
    return count;
  }
};

// TC __________ O(m+n)

// 1351. Count Negative Numbers in a Sorted Matrix

// Given a m x n matrix grid which is sorted in non-increasing order both
// row-wise and column-wise, return the number of negative numbers in grid.

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0