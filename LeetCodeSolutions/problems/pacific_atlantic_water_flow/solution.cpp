class Solution
{
public:
  std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights);

private:
  int _ROWS;
  int _COLS;
  std::vector<std::vector<bool>> _pacific;
  std::vector<std::vector<bool>> _atlantic;

  void dfs(int curRow, int curCol, int prevHeight, std::vector<std::vector<bool>> &visited, std::vector<std::vector<int>> &heights);
};

std::vector<std::vector<int>> Solution::pacificAtlantic(std::vector<std::vector<int>> &heights)
{
  // Initialize the Obj
  _ROWS = heights.size();
  _COLS = heights[0].size();

  _pacific = std::vector<std::vector<bool>>(_ROWS, std::vector<bool>(_COLS, false));
  _atlantic = std::vector<std::vector<bool>>(_ROWS, std::vector<bool>(_COLS, false));

  // Check Bottom and Upper bounds
  for (int col = 0; col < _COLS; col++)
  {
    dfs(0, col, heights[0][col], _pacific, heights);
    dfs(_ROWS - 1, col, heights[_ROWS - 1][col], _atlantic, heights);
  }

  // Check left and right bounds
  for (int row = 0; row < _ROWS; row++)
  {
    dfs(row, 0, heights[row][0], _pacific, heights);
    dfs(row, _COLS - 1, heights[row][_COLS - 1], _atlantic, heights);
  }

  std::vector<std::vector<int>> result;
  for (int r = 0; r < _ROWS; r++)
  {
    for (int c = 0; c < _COLS; c++)
    {
      if (_pacific[r][c] && _atlantic[r][c])
      {
        result.push_back({r, c});
      }
    }
  }

  return result;
}

void Solution::dfs(int curRow, int curCol, int prevHeight, std::vector<std::vector<bool>> &visited, std::vector<std::vector<int>> &heights)
{   
  // cout << "-- curCOl " << curCol << " curRow " << curRow <<"\n";
  // Reached Boundary Condition
  if (curRow < 0 || curRow == _ROWS || curCol < 0 || curCol == _COLS)
  {
    return;
  }

  // Already a Visited Node or Lower hight
  if (visited[curRow][curCol] || heights[curRow][curCol] < prevHeight)
  {
    return;
  }

  visited[curRow][curCol] = true;
  // cout << "curCOl " << curCol << " curRow " << curRow <<"\n";

  // Check North, West, East and South Directions
  dfs(curRow + 1, curCol, heights[curRow][curCol], visited, heights);
  dfs(curRow - 1, curCol, heights[curRow][curCol], visited, heights);
  dfs(curRow, curCol + 1, heights[curRow][curCol], visited, heights);
  dfs(curRow, curCol - 1, heights[curRow][curCol], visited, heights);
  return;
}
