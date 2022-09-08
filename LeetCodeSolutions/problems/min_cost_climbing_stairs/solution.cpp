class Solution {
public:
    
    // Recursive Solution
    int minCostClimbingStairs(vector<int>& cost){
        int size = cost.size();
        vector<int> memo(size + 1, 0);
        return std::min(dfs(size - 1, cost, memo), dfs(size - 2, cost, memo));
    }
    
private:
    int dfs(int pos, vector<int> &cost, vector<int> &memo){
        if(pos < 0) return 0 ;
        
        if(pos == 1 || pos == 0)
        {
            memo[pos] = cost[pos];
            return memo[pos];
        }
        
        if(memo[pos] != 0) return memo[pos];
        
        memo[pos] = std::min(dfs(pos -1 , cost, memo), dfs(pos - 2, cost, memo)) + cost[pos];
        return memo[pos];
    }
        
    // Tabulation Bottom Up solution
//     int minCostClimbingStairs(vector<int>& cost) {
//         int size = cost.size();
//         vector<int> costs(size, 0);
    
//         // Iteration
//         for(int step = 0; step < size; step++)
//         {
//             if(step <= 1) costs[step] = cost[step];
//             else{
//                 costs[step] = std::min(costs[step - 1], costs[step - 2]) + cost[step];
//             }
//         }
        
//         // At the End the Final step cost is the minimum cost of the two prev
//         return std::min(costs[size - 1], costs[size - 2]);
//     }
};