class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){    
        string pfx = "";

        // Take the first String as an arbitrary point
        for(int iPfx = 0; iPfx < strs[0].size(); iPfx++){
            // Loop each character and check if it is a common prefix among other strings
            for(auto str : strs){
                if(iPfx == str.size() || str[iPfx] != strs[0][iPfx]) return pfx;
            }
            // Append the character to the pfx holder
            pfx.push_back(strs[0][iPfx]);
        }
        return pfx;
    }
};