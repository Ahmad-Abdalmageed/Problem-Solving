class Solution {
public:
    string convert(string s, int numRows){
        string res; 
        int element;

        // Edge Case, numRows == 1
        if (numRows == 1) return s ;

        // Element incrementing and Zigzag Formation
        for(int r = 0; r <= numRows - 1; r++){
            element = 2* (numRows - 1);
            for(int i = r; i < s.size() ; i = i + element){
                res.push_back(s[i]);

                // Case : Middle Rows Elements 
                if( (r > 0) && (r < numRows - 1) && (i + element - 2*r < s.size()) ){
                    res.push_back(s[i + element - 2*r]);
                }
            }
        }

        return res;
    }

};