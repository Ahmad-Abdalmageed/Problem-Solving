class Solution {
public:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
  std::priority_queue<std::tuple<int, int, int>, vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> bfs;

  vector<int> distances(n+1, INT_MAX);

  unordered_map<int, vector<vector<int>>> adjList;

  for (auto const &flight : flights)
  {
    adjList[flight[0]].push_back({flight[2], flight[1]});
  }

  bfs.emplace(0, src, 0);

  while (!bfs.empty())
  {
    auto [cost, currentPos, stops] = bfs.top();

    bfs.pop();

    if (currentPos == dst)
    {
      return cost;
    }
    if (distances[currentPos] < stops)
    {
      continue;
    }

    distances[currentPos] = stops;

    if (stops > k)
    {
      continue;
    }

    // Check Next Stops
    for (auto const &nextFlight : adjList[currentPos])
    {
      int nextPos = nextFlight[1];
      int nextCost = nextFlight[0];
      bfs.emplace(cost + nextCost, nextPos, stops + 1);
    }
  }
  return -1;
}
};