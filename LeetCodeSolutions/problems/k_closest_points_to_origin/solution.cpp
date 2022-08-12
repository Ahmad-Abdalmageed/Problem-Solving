class Solution {
public:
// LEETCODE:973. K Closest Points to Origin
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
  std::priority_queue<std::pair<double, int>> minHeap;

  // Create the Min Heap
  for (int pointIdx = 0; pointIdx < points.size(); pointIdx++)
  {
    int x = points[pointIdx][0];
    int y = points[pointIdx][1];
    double distance = std::sqrt(std::pow(x, 2) + std::pow(y, 2));

    minHeap.push({distance, pointIdx});

    // Keep MinHeap Size restricted to K
    if (minHeap.size() > k)
      minHeap.pop();
  }

  // Get K elements from heap
  std::vector<std::vector<int>> result;
  while (!minHeap.empty())
  {
    result.push_back(points[minHeap.top().second]);
    minHeap.pop();
  }

  return result;
}
};