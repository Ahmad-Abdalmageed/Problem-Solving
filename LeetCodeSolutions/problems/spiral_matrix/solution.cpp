class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        _visited = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        _cols = matrix[0].size();
        _rows = matrix.size();
        
        solve(matrix, 0, 0, false);
        return _spiralArr;
    }
    
private:
    vector<int> _spiralArr;
    vector<vector<int>> _visited;
    int _cols;
    int _rows;
    
    void solve(vector<vector<int>>& matrix, int curRow, int curCol, bool isUp)
    {
        if(curRow < 0 || curRow >= _rows || curCol < 0 || curCol >= _cols) return;
        if( _visited[curRow][curCol]) return ;
        
        // cout << curRow << ":" << curCol << "\n" ;
        
        _spiralArr.push_back(matrix[curRow][curCol]);
        _visited[curRow][curCol] = 1;
        
        // Continue Going up untill last visited cell
        if(isUp) solve(matrix, curRow - 1, curCol, true);
        
        // Go Right;
        solve(matrix, curRow, curCol + 1, false);
        
        // Go Down
        solve(matrix, curRow + 1, curCol, false);
        
        // Go Left
        solve(matrix, curRow, curCol - 1, false);
        
        // Go Up
        solve(matrix, curRow - 1, curCol, true);
        
    }
};