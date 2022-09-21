class Solution {
public:
    int longestCommonSubsequence(string text1, string text2);
private:
    vector<vector<int>> memo;
    int findSubSequence(string &text1, string &text2, int i, int j);
};


int Solution::longestCommonSubsequence(string text1, string text2)
{
    memo = vector<vector<int>>(text1.size() + 1, vector<int>(text2.size() + 1));
    
    for(int i = 1; i <= text1.size(); i++)
    {
        for(int j = 1; j <= text2.size(); j++)
        {
            if(text1[i - 1] == text2[j - 1])
            {
                memo[i][j] = 1 + memo[i - 1][j - 1];
            } 
            else 
            {
                memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    
    return memo[text1.size()][text2.size()];
}

// int Solution::longestCommonSubsequence(string text1, string text2)
// {
//     memo = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
//     return findSubSequence(text1, text2, 0 , 0);
// }

// int Solution::findSubSequence(string &text1, string &text2, int i, int j)
// {
//     // Base Case
//     if(i == text1.size() || j == text2.size())
//     {
//         return 0;
//     }
    
//     if(memo[i][j] != -1) return memo[i][j];
    
//     // Move Both I and J
//     if(text1[i] == text2[j])
//     {
//         return memo[i][j] = 1 + findSubSequence(text1, text2, i + 1, j + 1);
//     } // Get Max Sequence from both dirs
//     else 
//     {
//         return memo[i][j] = std::max(findSubSequence(text1, text2, i + 1, j), findSubSequence(text1, text2, i, j + 1));
//     }
// }