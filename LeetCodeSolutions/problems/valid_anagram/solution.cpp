class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        
        std::sort(s.begin(), s.end()); // nlogn
        std::sort(t.begin(), t.end()); // nlogn
        
        int i = 0;
        int j = 0;
        
        // o(m) m = s.size()
        while(i <= s.size() && j <= t.size())
        {
            if(s[i] != t[j]) return false;
            i++;
            j++;
            
        }
        return true;
        
    }
};