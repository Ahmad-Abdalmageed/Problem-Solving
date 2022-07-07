class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    typedef std::pair<int, int> pi;

    // Create an Adjacency Hash Map
    std::map<int, std::vector<pi>> neighbors;
    // For Every Node add its Neighbors
    for (auto edge : times) {
      // std::cout << edge[0] << ":" << edge[1] << ", " << edge[2] << '\n';
      neighbors[edge[0]].push_back({edge[1], edge[2]});
    }

    // Create a Min Heap -- Priority Queue ,
    // That will hold the next Minimum Distance To Cover
    std::priority_queue<pi, std::vector<pi>, std::greater<pi>> nextMin;
    nextMin.push({0, k}); // Add the First Node

    std::vector<int> visited(n, 0);
    int totalTime = 0;

    // Breadth First Search of the Best Time --- Dijkstras`s Algorithm
    while (!nextMin.empty()) {
      // Peak the First Node
      int curTime = nextMin.top().first;
      int curNode = nextMin.top().second;

      nextMin.pop();

      // Skip if Already Visited
      if (visited[curNode - 1])
        continue;
      visited[curNode - 1] = 1;
      totalTime = std::max(totalTime, curTime);

      // Loop Neighbors
      for (auto &[nextNode, nextTime] : neighbors[curNode]) {
        // Add Neighbors if not visited, with times to reach from origin node
        if (!visited[nextNode - 1])
          nextMin.push({nextTime + curTime, nextNode});
      }
    }
    return std::count(visited.begin(), visited.end(), 1) == n ? totalTime: -1;
  }

};