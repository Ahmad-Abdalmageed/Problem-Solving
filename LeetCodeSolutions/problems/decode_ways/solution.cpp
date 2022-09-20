class Solution {
public:
    int numDecodings(string s);
private:
    std::vector<int> memo;
    int decodeWays(string &s, int curIdx);
};

int Solution::numDecodings(string s)
{
    std::vector<int> dp(s.size() + 1, 0);
    
    dp[0] = s[0] != '0' ? 1 : 0;
    
    for(int curIdx = 1; curIdx <= s.size(); curIdx++)
    {
        if(s[curIdx] >= '1' && s[curIdx] <= '9')
            dp[curIdx] = dp[curIdx - 1];
        
        if(s[curIdx - 1] == '1' || (s[curIdx - 1] == '2' && s[curIdx] <= '6'))
        {
            dp[curIdx] += curIdx >= 2 ? dp[curIdx - 2]: 1;
        }

    }
    return dp[s.size() - 1];
}


//  Recursive Solution + Memoization
// int Solution::numDecodings(string s)
// {
//     memo = std::vector<int>(100, 0);
//     return decodeWays(s, 0);
// }


// int Solution::decodeWays(string &s, int curIdx)
// {
//     // Reached End of String
//     if(curIdx == s.size()) return 1;
    
//     if(memo[curIdx] != 0) return memo[curIdx];
    
//     int ans = 0;
    
//     // Consider Current Digit
//     if(s[curIdx] != '0')
//     {
//         ans += decodeWays(s, curIdx + 1);
//     }
    
//     if(curIdx + 1 < s.size() && (s[curIdx] == '1' || s[curIdx] == '2' && s[curIdx + 1] <= '6'))
//     {
//         ans += decodeWays(s, curIdx + 2);
//     }
//     memo[curIdx] = ans;
//     return ans;
// }
