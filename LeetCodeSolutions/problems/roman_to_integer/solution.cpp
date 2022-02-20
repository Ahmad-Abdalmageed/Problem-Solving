class Solution {
public:
    int romanToInt(string s) {
        int res = 0; 
        int i = 0;
        map<char, int> romans = {
            { 'M' , 1000},
            { 'D' , 500 },
            { 'C' , 100 },
            { 'L' , 50  },
            { 'X' , 10  },
            { 'V' , 5   },
            { 'I' , 1   },
        };

        while(i < s.size()){
            if(i+1 < s.size() && romans[s[i+1]] > romans[s[i]]){
                res = res + (romans[s[i+1]] - romans[s[i]]);
                i = i + 2;
             } else{
                res = res + romans[s[i]];
                i++;

            }
        }
        return res;
    }


};