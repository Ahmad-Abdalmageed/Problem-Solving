class Solution {
public:
    int strStr(string haystack, string needle){
        // Empty string case 
        if(needle == "") return 0;

        // needle longer than haystack
        if(needle.size() > haystack.size()) return -1;

        int i = 0;
        int j = 0;
        // Preprocess the needle for lps
        vector<int> needleLPS = lps(needle);

        while(i < haystack.size()){
            // while matching substrings continue to advance
            if(haystack[i] == needle[j]){
                i++;
                j++;
            } else {
                // found a non matching substrings only advance the haystack pointer
                if (j == 0) i++;

                // backtrack the needle pointer untill matching substrings
                else j = needleLPS[j - 1];
            }

            // at reaching the end of the needle return the substring starting position
            if(j == needle.size()) return i - needle.size();
        }

        // case no matches found
        return -1;
    }

    vector<int> lps(string needle){
        vector<int> lps(needle.size(), 0);
        int prvLPS = 0;
        int curLPS = 1;

        // find the portion of the needle where
        // the needle suffix is the needle prefix
        while(curLPS < needle.size()){
            if(needle[curLPS] == needle[prvLPS]){
                lps[curLPS] = prvLPS + 1;
                prvLPS++;
                curLPS++;
            } else if (prvLPS == 0){
                lps[curLPS] = 0;
                curLPS++;
            } else {
                prvLPS = lps[prvLPS - 1];
            }
        }
        return lps;
    }
};