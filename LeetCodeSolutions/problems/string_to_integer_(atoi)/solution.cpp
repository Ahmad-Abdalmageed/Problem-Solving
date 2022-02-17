class Solution {
public:
int myAtoi(string s){
    int res = 0;
    int digit;
    int sign = 1;
    int MAX = INT32_MAX;
    int MIN = INT32_MIN;
    int c = 0;
    
    // Increment untill first non-white space is found and ignore + sign
    while((int)s[c] == 32) c++;

    // Check Char for sign
    if((int)s[c] == 45 || (int)s[c] == 43){
            sign= s[c]=='-' ? -1 : 1;
        c++;
    }
    // Only convert characters in range of digits
    // 0 - 9 --> 48 - 57
    while((int)s[c] >= 48 && (int)s[c] <= 57){
        // Convert Current Digit
        digit = (s[c] - '0') *sign;
        // Check for Bounds

        if(res > MAX / 10 || (res == MAX / 10 && digit > MAX%10 )) return MAX;
        if(res < MIN / 10 || (res == MIN / 10 && digit < MIN%10 )) return MIN;

        // Shft the result left by one
        //  Add the converted digit
        res = res * 10 + digit ;

        // Increment
        c++;
    } 

    return res;
}

};