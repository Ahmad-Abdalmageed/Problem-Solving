class Solution {
public:
    int coinChange(vector<int>& coins, int amount);
private:
    vector<int> dp;
    int coinCounter(vector<int> &coins, int amount, int coint);
};


int Solution::coinChange(vector<int>& coins, int amount)
{
    dp = vector<int>(amount + 1, amount + 1);
    dp[0] = 0;
    
    for(int rem = 1; rem < amount + 1; rem++)
    {
        for(int coin = 0; coin < coins.size(); coin++)
        {
            if(rem - coins[coin] >= 0)
                dp[rem] = std::min(dp[rem], 1 + dp[rem - coins[coin]]);
        }
    }
    
    return dp[amount] == amount + 1 ? -1: dp[amount];
    
}



// Recursive + Memoization
// int Solution::coinChange(vector<int>& coins, int amount)
// {
    
//     dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, -1));
    
//     int res = coinCounter(coins, amount, 0);
//     return res == INT_MAX - 1 ? -1 : res;
// }

// int Solution::coinCounter(vector<int> &coins, int amount, int coin)
// {
//     if(amount == 0) return 0;
//     if(coin == coins.size()) return INT_MAX - 1;
    
//     if(dp[coin][amount] != -1) return dp[coin][amount];
    
//     if(coins[coin] <= amount)
//     {
//         return dp[coin][amount] = std::min(1 + coinCounter(coins, amount - coins[coin], coin), coinCounter(coins, amount, coin + 1));
//     }
//     else 
//     {
//         return dp[coin][amount] = coinCounter(coins, amount, coin + 1);
//     }
// }