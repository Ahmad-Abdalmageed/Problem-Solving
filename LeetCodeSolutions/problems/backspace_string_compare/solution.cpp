class Solution {
public:
    // LEETCODE: 844. Backspace String Compare -- ALGORITHMS II
    bool backspaceCompare(string s, string t){
        // Two Pointers Approach --- REVERSED Iteration
        int sPtr = s.size()-1, tPtr = t.size()-1;
        int skipS = 0, skipT = 0;


        while(sPtr >= 0 || tPtr >=0){
            // Find Position of next non Backspace Char
            while(sPtr >= 0){
                if(s[sPtr] == '#'){
                    skipS++;
                    sPtr--;
                } else if (skipS >0){
                    skipS--;
                    sPtr--;
                } else {
                    // Found Next Non Back Space
                    break;
                }
            }

            while(tPtr >= 0){
                if(t[tPtr] == '#'){
                    skipT++;
                    tPtr--;
                } else if (skipT >0){
                    skipT--;
                    tPtr--;
                } else {
                    // Found Next Non Back Space
                    break;
                }
            }


            // Compare Found Chars 
            if(sPtr >= 0 && tPtr >=0 && s[sPtr] != t[tPtr]) return false;
            if( (sPtr >= 0) != (tPtr >= 0) ) return false;
            
            sPtr--;
            tPtr--;
        }
        return true;

    }

};