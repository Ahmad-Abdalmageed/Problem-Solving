class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int result = startValue;
        int opCount = 0;

        while(target > startValue){
            opCount++;
            if(target % 2 == 0 ) target /= 2;
            else target++;
        }
        return opCount + (startValue - target);
    }
};