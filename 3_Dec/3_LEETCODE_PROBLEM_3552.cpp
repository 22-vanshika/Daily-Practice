// 3552. Grid Teleportation Traversal

// You are given a 2D character grid matrix of size m x n, represented as an
// array of strings, where matrix[i][j] represents the cell at the intersection
// of the ith row and jth column. Each cell is one of the following:

// '.' representing an empty cell.
// '#' representing an obstacle.
// An uppercase letter ('A'-'Z') representing a teleportation portal.
// You start at the top-left cell (0, 0), and your goal is to reach the
// bottom-right cell (m - 1, n - 1). You can move from the current cell to any
// adjacent cell (up, down, left, right) as long as the destination cell is
// within the grid bounds and is not an obstacle.

// If you step on a cell containing a portal letter and you haven't used that
// portal letter before, you may instantly teleport to any other cell in the
// grid with the same letter. This teleportation does not count as a move, but
// each portal letter can be used at most once during your journey.

// Return the minimum number of moves required to reach the bottom-right cell.
// If it is not possible to reach the destination, return -1.

// Example 1:

// Input: matrix = ["A..",".A.","..."]

// Output: 2

// Explanation:

// Before the first move, teleport from (0, 0) to (1, 1).
// In the first move, move from (1, 1) to (1, 2).
// In the second move, move from (1, 2) to (2, 2).

class Solution {
public:
  int minMoves(vector<string> &matrix) {
    vector<vector<pair<int, int>>> v(26);
    int m = matrix.size(), n = matrix[0].length();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] != '.' and matrix[i][j] != '#') {
          v[matrix[i][j] - 'A'].push_back({i, j});
        }
      }
    }
    queue<pair<pair<int, int>, int>> pq;
    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    vis[0][0] = 1;
    if (matrix[0][0] == '.')
      pq.push({{
                   0,
                   0,
               },
               0});
    else {
      int idx = matrix[0][0] - 'A';
      for (auto j : v[idx]) {
        vis[j.first][j.second] = 1;
        pq.push({{j}, 0});
      }
    }
    vector<vector<int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    while (!pq.empty()) {
      int i = pq.front().first.first, j = pq.front().first.second,
          cost = pq.front().second;
      pq.pop();
      if (i == m - 1 and j == n - 1)
        return cost;
      for (int k = 0; k < 4; k++) {
        int ni = i + dir[k][0], nj = j + dir[k][1];
        if (ni >= 0 and ni < m and nj >= 0 and nj < n and !vis[ni][nj] and
            matrix[ni][nj] != '#') {
          vis[ni][nj] = 1;
          if (matrix[ni][nj] == '.')
            pq.push({{ni, nj}, cost + 1});
          else {
            int idx = matrix[ni][nj] - 'A';
            for (auto j : v[idx]) {
              pq.push({{j}, cost + 1});
              vis[j.first][j.second] = 1;
            }
          }
        }
      }
    }
    return -1;
  }
};