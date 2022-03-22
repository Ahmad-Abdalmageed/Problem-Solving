class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        // Initialize the values needed 
        int rows = mat.size();
        int cols = mat[0].size();
        std::queue<std::pair<int, int>> zeros;
        std::vector<std::vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        // Loop and push each zero location inside the queue
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    zeros.push({i, j});
                }
            }
        }

        // for the all neighbors arround the zero-cell
        vector<vector<int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!zeros.empty()){
            // Extract the current zero cell
            std::pair<int, int> curr = zeros.front();
            zeros.pop();

            for(auto dir: dirs){
                int new_r = curr.first + dir[0];
                int new_c = curr.second + dir[1];

                // Check Boundary
                if(new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols){

                    if(dist[new_r][new_c] > dist[curr.first][curr.second]+1){
                        dist[new_r][new_c] = dist[curr.first][curr.second]+1;
                        zeros.push({new_r, new_c});
                    }
                }
            }   
        }
        return dist;
    }

};