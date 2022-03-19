class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

private:
    int bfs(int row, int col);
    int gRows = 0;
    int gCols = 0;
    std::vector<std::vector<int>> island;
    std::vector<std::vector<bool>> seen;
};

int Solution::bfs(int row, int col){
    if(row >= gRows || col >= gCols || row < 0 || col < 0 || seen[row][col] || island[row][col] == 0) return 0;
    seen[row][col] = true;
    return 1 + bfs(row-1, col) + bfs(row+1, col) + bfs(row, col-1) + bfs(row, col+1);
}

int Solution::maxAreaOfIsland(std::vector<std::vector<int>>& grid){
    // Store Island Properties
    gRows = grid.size();
    gCols = grid[0].size();
    seen = std::vector<std::vector<bool>> (gRows, std::vector<bool>(gCols));
    island = grid;

    // BFS Algorithm --- Look in each connected structure for the new maximum area
    int ans = 0;
    for(int i = 0; i < gRows; i++){
        for(int j = 0; j < gCols; j++){
            ans = std::max(ans, bfs(i, j));
        }
    }

    return ans;
}