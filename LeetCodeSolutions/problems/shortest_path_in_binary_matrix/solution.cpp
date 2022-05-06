class Solution {
public:
// LEETCODE: Shortest Path in Binary Matrix
int shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid) {
  // Set Up Directions 
  int rGridSize = grid.size();
  int cGridSize = grid[0].size();
  std::vector<std::pair<int, int>> dirs = {{-1, -1}, {0, -1}, {-1, 0}, {1, 1},
                                        {1, 0},   {0, 1},  {1, -1}, {-1, 1}};

  // Base Case where no path is available to the target
  if(grid[0][0] || grid[rGridSize-1][cGridSize-1]) return -1;
  
  // Take the First Step
  grid[0][0] = 1;
  std::queue<std::vector<int>> pathSearchQueue;
  pathSearchQueue.push({0, 0, 1});

  // Find All Paths
  while(!pathSearchQueue.empty()){
    // Extract Current Node
    int r = pathSearchQueue.front()[0];
    int c = pathSearchQueue.front()[1];
    int dist = pathSearchQueue.front()[2];
    pathSearchQueue.pop();

    // Return when reaches the Target
    if(r == rGridSize-1 && c == cGridSize-1) return dist;

    // Search in Every Direction
    for(auto const &[dr, dc]: dirs){
      int rNew = r + dr;
      int cNew = c + dc;

      if(rNew >= 0 && rNew < rGridSize && cNew >=0 && cNew < cGridSize && !grid[rNew][cNew]){
        pathSearchQueue.push({rNew, cNew, dist+1});
        grid[rNew][cNew] = 1;
      }
    }
  }
  return -1;
}

};