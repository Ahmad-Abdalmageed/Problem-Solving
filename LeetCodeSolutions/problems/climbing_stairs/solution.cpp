class Solution {
public:
    // Recursion + Memoization
    int climbStairs(int n) {
        vector<int> memo(n + 1, 0);
        return dfs(0, n, memo);
    }
    
private: 
    
    int dfs(int curNode, int n, vector<int> &memo){
        if(curNode > n)
            return 0;
    
        if(memo[curNode] != 0)
            return memo[curNode];
        
        if(curNode == n)
            return 1;
        
        memo[curNode] = dfs(curNode + 1, n, memo) + dfs(curNode + 2, n, memo);
        return memo[curNode];
        
    }
};

    // Tabulation Solution
//     int climbStairs(int n) {
//         // Base Case 
//         if(n == 1) return 1;
        
//         vector<int> stairs(n+1, 0);
//         stairs[1] = 1;
//         stairs[2] = 1;
        
//         for(int iStair = 0; iStair < n+1 ; iStair++){
//             if(iStair + 1 < n + 1)
//                 stairs[iStair + 1] += stairs[iStair] ;
//             if(iStair + 2 < n + 1)
//                 stairs[iStair + 2] += stairs[iStair];
//         }
        
//         return stairs[n];
//     }
