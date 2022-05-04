class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected);
private:
  void bfs(std::vector<std::vector<int>>& isConnected, int cur);
  std::vector<bool> visited;
};

int Solution::findCircleNum(std::vector<std::vector<int>>& isConnected){
  visited = std::vector<bool>(isConnected.size());
  int islandsCount = 0;
  for(int city = 0; city < isConnected.size(); city++){
    if(!visited[city]){
      bfs(isConnected, city);
      islandsCount++;
    }
  }
  return islandsCount;
}
void Solution::bfs(std::vector<std::vector<int>>& isConnected, int cur){
  for(int nextCity = 0; nextCity < isConnected.size(); nextCity++){
    if(isConnected[cur][nextCity] && !visited[nextCity]){
      visited[nextCity] = 1;
      bfs(isConnected, nextCity);
    }
  }
}