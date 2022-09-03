class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid);

private:
  vector<vector<int>> _dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};


int Solution::swimInWater(vector<vector<int>> &grid)
{
  int gridSize = grid.size();
  // if Grid is only one tile
  if (gridSize == 1)
    return 0;

  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> bfs;
  vector<vector<bool>> visited(gridSize, vector<bool>(gridSize, false));
  visited[0][0] = true;
  int result = max(grid[0][0], grid[gridSize - 1][gridSize - 1 ]);

  bfs.push({result, 0, 0});
  while (!bfs.empty())
  {
    vector<int> currentPosition = bfs.top();
    bfs.pop();
    
    result = max(currentPosition[0], result);

    for (int dir = 0; dir < 4; dir++)
    {
      int x = currentPosition[1] + _dirs[dir][0];
      int y = currentPosition[2] + _dirs[dir][1];

      if (x == gridSize - 1 && y == gridSize - 1)
      {
        return result;
      }

      if (x < 0 || x >= gridSize || y < 0 || y >= gridSize || visited[x][y])
      {
        continue;
      }

      bfs.push({grid[x][y], x, y});
      visited[x][y] = true;
    }
  }

  // Reachable only if no solution exists
  return -1;
}