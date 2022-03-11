class Solution {
public:

    int divide(int dividend, int divisor) {
        
        // Edge cases : OVERFLOW in minimum direction
        if(dividend == INT32_MIN && divisor == -1) return INT32_MAX;
        if(dividend == INT32_MIN && divisor == 1) return INT32_MIN;

        // Keep both numbers with the same neative sign as to be always in valid 
        // 32-bit range
        int up = (dividend > 0) ? -dividend: dividend;
        int down = (divisor > 0) ? -divisor: divisor;

        // Determine the calculation sign
        bool negative = (dividend < 0 ) ^ (divisor<0);

        // Find the maximum exponential increase of the accumlator
        int exp_inc = down;
        int multiplier = 1;

        int qoutient = 0;

        // Keep doubling the accumlator untill overflow or maximum value
        while((exp_inc >= (INT32_MIN >> 1)) && (up <= exp_inc + exp_inc) ){
            exp_inc += exp_inc;
            multiplier <<= 1;
        }   
        
        cout << multiplier << endl;
        while(up <= down){
            if(up <= exp_inc){
                up -= exp_inc;
                qoutient += multiplier;
            }
            exp_inc >>= 1;
            multiplier >>= 1;
        }
        return negative ? -qoutient : qoutient;
    }

};