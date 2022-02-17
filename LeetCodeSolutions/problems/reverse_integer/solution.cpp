class Solution {
public:
    int reverse(int x) {
        int digit;
        int res = 0;
        int MAX = 2147483647;
        int MIN = -MAX;

        while(x != 0){
            //  Check Result out of bounds
            if(res > MAX / 10 || (res == MAX / 10 && digit >= MAX%10 )) return 0;
            if(res < MIN / 10 || (res == MIN / 10 && digit <= MIN%10 )) return 0;

            // Extract each digit from X and Reverse 
            digit = x % 10 ;
            x = x / 10;
            res = (res * 10) + digit;
        }

        return res;
    }
};