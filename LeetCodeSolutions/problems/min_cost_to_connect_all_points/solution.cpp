class Solution {
public:
// LEETCODE: 1584. Min Cost to Connect All Points
int minCostConnectPoints(vector<vector<int>> &points)
{
  priority_queue<pair<int, int>> dfs;
  vector<bool> visited(points.size(), false);
  int connectedNodes = 1;
  int minCost = 0;
  int currentPoint = 0;

  while (connectedNodes < points.size())
  {
    visited[currentPoint] = true;
    for (int point = 0; point < points.size(); point++)
    {
      if (!visited[point])
      {
        int cost = abs(points[currentPoint][0] - points[point][0]) + abs(points[currentPoint][1] - points[point][1]);
        dfs.push({-cost, point});
      }
    }
    while (visited[dfs.top().second])
    {
      dfs.pop();
    }

    minCost -= dfs.top().first;
    currentPoint = dfs.top().second;
    dfs.pop();
    connectedNodes++;
  }

  return minCost;
}

};