class Solution
{
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges);

private:
  unordered_map<int, vector<int>> _graph;

  bool hasCycle(unordered_set<int> &visited, int start, int prev = -1);
};

vector<int> Solution::findRedundantConnection(vector<vector<int>> &edges)
{
  int start = edges[0][0];
  vector<int> cyclicEdge;

  for (auto const &edge : edges)
  {
    unordered_set<int> visited;

    _graph[edge[0]].push_back(edge[1]);
    _graph[edge[1]].push_back(edge[0]);

    if (hasCycle(visited, edge[0]))
    {
      cyclicEdge = edge;
      break;
    }
  }

  return cyclicEdge;
}

bool Solution::hasCycle(unordered_set<int> &visited, int start, int prev)
{
  if (visited.find(start) != visited.end())
    return true;

  visited.insert(start);

  for (auto const &neighbor : _graph[start])
  {
    if (prev != neighbor && hasCycle(visited, neighbor, start))
      return true;
  }
  return false;
}
