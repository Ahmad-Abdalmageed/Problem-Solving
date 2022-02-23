class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int i=0;
        map<char, int> hash;
        
        for(int j=0;j<s.size();j++){
            if(hash.find(s[j]) != hash.end()){
                i = max(hash[s[j]], i);
            }
            res = max(res, j-i+1);
            hash[s[j]] = j+1;
        }
        return res;

    }
};