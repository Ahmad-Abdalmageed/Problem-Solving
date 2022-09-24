class Solution {
public:
    vector<int> memo;
    int n;
    int maxScore(vector<int>& nums) 
    {
        memo = vector<int>(1 << 14, 0);
        n = nums.size() / 2;
        return dp(nums, 1, 0)  ; 
    }
private:
    int dp(vector<int> &nums, int op, int mask)
    {
        if(op > n) return 0;
        if(memo[mask] != 0) return memo[mask];
        
        // Choose Two Numbers
        for(int i = 0; i < nums.size(); i++)
        {
            if((mask >> i) & 1) continue;
            for(int j = i + 1; j < nums.size(); j++)
            {
                if((mask >> j) & 1) continue;
                int newMask = (1 << i) | (1 << j) | mask;
                int score = op * __gcd(nums[i], nums[j]) + dp(nums, op + 1, newMask);
                memo[mask] = std::max(score, memo[mask]);
                
            }
        }
        return memo[mask];
    }
};