class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict);
private: 
    vector<char> memo;
    bool wordFinder(int start, string &s, unordered_set<string> &wordSet);
};

bool Solution::wordBreak(string s, vector<string>& wordDict)
{
    memo = vector<char>(s.size(), -1);
    
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    return wordFinder(0, s, wordSet);
}


bool Solution::wordFinder(int start, string &s, unordered_set<string> &wordSet)
{
    if(s.size() == start)
    {
        return true;
    }
    if(memo[start] != -1) return memo[start];
    
    string sub;
    for(int idx = start; idx < s.size(); idx++)
    {
        sub += s[idx];
        if( wordSet.count(sub) > 0 && wordFinder(idx + 1, s, wordSet) )
        {
            memo[start] = true;
            return memo[start];
        }
    }
    memo[start] = false;
    return memo[start];
}
