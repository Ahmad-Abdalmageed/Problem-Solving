class Solution {
public:
  void solve(std::vector<std::vector<char>> &board);
private:
  void dfs(int r, int c, std::vector<std::vector<char>> &board);
  int mapRows;
  int mapCols;
};

void Solution::solve(std::vector<std::vector<char>> &board) {
  // Using Reverse Thinkinh and a Combination of DFS and Loops
  // To first Identify the unsurrounded Regions of the map
  // Then easily return the Surrounded Regions
  mapRows = board.size();
  mapCols = board[0].size();

  // Capture Unsurrounded Regions on the borders of the board
  for (int r = 0; r < mapRows; r++) {
    for (int c = 0; c < mapCols; c++) {
      // Check if Border Cell
      if (board[r][c] == 'O' &&
          ((r == 0 || r == mapRows - 1) || (c == 0 || c == mapCols - 1)))
        this->dfs(r, c, board);
    }
  }

  // Capture Surrounded Area
  for (int r = 0; r < mapRows; r++) {
    for (int c = 0; c < mapCols; c++) {
      if (board[r][c] == 'O')
        board[r][c] = 'X';
    }
  }

  // Return Temporary Unsurrounded Areas 
  for (int r = 0; r < mapRows; r++) {
    for (int c = 0; c < mapCols; c++) {
      if (board[r][c] == 'T')
        board[r][c] = 'O';
    }
  }
}
void Solution::dfs(int r, int c,
                            std::vector<std::vector<char>> &board) {
  // Base Case Check, Out of Bounds and not o's Cells
  if (r < 0 || c < 0 || r == mapRows || c == mapCols || board[r][c] != 'O')
    return;

  board[r][c] = 'T';
  dfs(r + 1, c, board);
  dfs(r - 1, c, board);
  dfs(r, c + 1, board);
  dfs(r, c - 1, board);
}
