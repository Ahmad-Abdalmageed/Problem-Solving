class Solution {
public:
    int uniquePaths(int m, int n);
private:
    int _cols;
    int _rows;
    vector<vector<int>> memo;
    int followPath(int curRow, int curCol);
};

int Solution::uniquePaths(int m, int n)
{
    memo = vector<vector<int>>(m, vector<int>(n, 1));
    
    for(int curRow = 1; curRow < m; curRow++)
    {
        for(int curCol = 1; curCol < n; curCol++)
        {
            memo[curRow][curCol] = memo[curRow - 1][curCol] + memo[curRow][curCol - 1];
        }
    }
    return memo[m - 1][n - 1];
}
// int Solution::uniquePaths(int m, int n)
// {
//     memo = vector<vector<int>>(m, vector<int>(n, -1));
//     _rows = m;
//     _cols = n;
//     return followPath(0 , 0);
// } 

// int Solution::followPath(int curRow, int curCol)
// {
//     if(curRow < 0 || curRow >= _rows || curCol < 0 || curCol >= _cols)
//     {
//         return 0;
//     }
    
//     if(curCol == _cols - 1 && curRow == _rows - 1)
//     {
//         return 1;
//     }
    
//     if(memo[curRow][curCol] != -1) return memo[curRow][curCol];
    
//     memo[curRow][curCol] = followPath(curRow + 1, curCol) + followPath(curRow, curCol + 1);
//     return memo[curRow][curCol];
// }