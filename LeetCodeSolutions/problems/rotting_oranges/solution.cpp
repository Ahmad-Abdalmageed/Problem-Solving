class Solution {
public:
int orangesRotting(vector<vector<int>>& grid){
    // Create a Queue to hold rotten oranges which we can then loop 
    // and calculate the time simultaniously 
    std::queue<std::pair<int, int>> rotOranges= {};
    int time = 0, fresh = 0;

    int rows = grid.size(), cols = grid[0].size();

    // Append Rotten to Queue and count the Fresh Oranges
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(grid[i][j] == 1) fresh += 1;
            if(grid[i][j] == 2) rotOranges.push({i, j});
        }
    }

    vector<vector<int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    // For each Rotten Orange append adjasent oranges to Rot queue 
    // and Increase time by one unit increase
    while(!rotOranges.empty() && fresh > 0){

        // for the First Added rotten oranges loop to add neighbors 
        for(int orange = rotOranges.size()-1 ; orange >= 0; orange--){
            // Extract Current Orange Coordinates and remove it from queue
            int oRow = rotOranges.front().first;
            int oCol = rotOranges.front().second;
            rotOranges.pop();

            // Add neighbors to the queue using dirs 
            for(auto dir: dirs){
                // Calculate neighbor coordinates   
                int new_oRow = oRow + dir[0];
                int new_oCol = oCol + dir[1];

                // check boundary
                if(new_oRow < 0 || new_oRow == rows || new_oCol < 0 || new_oCol == cols || grid[new_oRow][new_oCol] != 1) continue;
                
                grid[new_oRow][new_oCol] = 2;
                rotOranges.push({new_oRow, new_oCol});
                fresh -= 1;
            }
        }
        time += 1;
    }

    // Return if all oranges are rotten
    return (fresh == 0) ? time: -1;
} 

};