class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // Store Grid Informations 
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> res(rows, vector<int>(cols));

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int pos1D = (r * cols + c + k) % (rows * cols);   
                int newR = pos1D / cols, newC = pos1D % cols;
                res[newR][newC] = grid[r][c];
            }
        }
        return res;
    }

};