class Solution {
public:
    bool isPalindrome(int x) {
        int xRev = 0;
        int digit ;
        int MAX = INT32_MAX;
        int MIN = INT32_MIN;

        // Return False if Negative Number
        if(x < 0 || (x % 10 == 0 && x != 0)) return 0;

        // Reverse the Input and Compare to Original
        while(x > xRev){
            xRev = xRev * 10 + x % 10;
            x = x / 10;
        }
        if (xRev == x || xRev/10 == x) return true;
        else return false;
    }

};