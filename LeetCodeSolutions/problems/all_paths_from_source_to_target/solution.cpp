class Solution {
public:
  std::vector<std::vector<int>>
  allPathsSourceTarget(std::vector<std::vector<int>> &graph);

private:
  void dfs(int pos, std::vector<std::vector<int>> &graph);
  std::vector<std::vector<int>> allPaths;
  std::vector<int> curPath;
};

std::vector<std::vector<int>>
Solution::allPathsSourceTarget(std::vector<std::vector<int>> &graph) {  
  // Start the DFS Algorithm
  this->dfs(0, graph);
  return this->allPaths;
}


void Solution::dfs(int pos, std::vector<std::vector<int>> &graph) {
  // Base Case: Reaching the End
  curPath.push_back(pos);

  // Base Case: Reached the Target
  if(pos == graph.size()-1) allPaths.push_back(curPath);
  // Loop all Candidate Paths from current position
  else{
    for(int nxtPos: graph[pos]){
      this->dfs(nxtPos, graph);
    }
  }
  // Backtracking
  curPath.pop_back();
}