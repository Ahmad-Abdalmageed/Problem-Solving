class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        // Create a DP Array
        std::vector<int> dp = triangle[triangle.size()-1];

        for(int row = triangle.size()-2; row >= 0; row--){
            for(int i = 0; i < triangle[row].size(); i++){
                dp[i] = triangle[row][i] + std::min(dp[i], dp[i+1]);
            }
        }
        return dp[0];
    }
};