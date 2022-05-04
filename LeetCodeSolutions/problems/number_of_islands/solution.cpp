class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid);

private:
  void bfs(int row, int col);
  std::vector<std::vector<bool>> seen;
  int gridRows;
  int gridCols;
  std::vector<std::vector<char>> gridIsland;
};

int Solution::numIslands(std::vector<std::vector<char>> &grid) {
  if (grid.empty())
    return 0;

  gridRows = grid.size();
  gridCols = grid[0].size();
  int islandsCount = 0;
  gridIsland = grid;
  seen = std::vector<std::vector<bool>>(gridRows, std::vector<bool>(gridCols));

  for (int r = 0; r < gridRows; r++) {
    for (int c = 0; c < gridCols; c++) {
      if (grid[r][c] == '1' && !seen[r][c]) {
        bfs(r, c);
        islandsCount++;
      }
    }
  }
  return islandsCount;
}
void Solution::bfs(int row, int col) {
  std::queue<std::pair<int, int>> neighbors;
  std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  seen[row][col] = 1;
  neighbors.push({row, col});

  while (!neighbors.empty()) {
    int r = neighbors.front().first;
    int c = neighbors.front().second;
    neighbors.pop();
    for (auto direction : directions) {
      int dr = r + direction[0];
      int dc = c + direction[1];

      if (dr >= 0 && dr < gridRows && dc >= 0 && dc < gridCols &&
          gridIsland[dr][dc] == '1' && !seen[dr][dc]) {
        neighbors.push({dr, dc});
        seen[dr][dc] = 1;
      }
    }
  }
}
