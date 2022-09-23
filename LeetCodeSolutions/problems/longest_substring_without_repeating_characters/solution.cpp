class Solution {
public:
int lengthOfLongestSubstring(string s) {
    int res = 0;
    int i=0;
    set<char> found;
    
    for(int j=0 ; j < s.size(); j++){
        //  remove Repeating chars from substring and count current lenght
        while(found.find(s[j]) != found.end()){
            found.erase(s[i]);
            i++;
        }
        found.insert(s[j]);
        res = max(res, j-i+1);
    }
    return res;
}

};