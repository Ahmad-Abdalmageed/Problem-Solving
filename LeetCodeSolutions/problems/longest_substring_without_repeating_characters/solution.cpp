class Solution {
public:
int lengthOfLongestSubstring(string s) {
    int res = 0;
    int i = 0, j = 0 ;
    std::unordered_set<char> sequence;
    
    while(j < s.size()){
        // Unique Characters go inside the Set
        if(sequence.find(s[j]) == sequence.end()){
            sequence.insert(s[j]);
            res = std::max(res, j - i + 1);
            j++;
        } else {
            sequence.erase(s[i]);
            i++;
        }
    }
    return res;
}

};