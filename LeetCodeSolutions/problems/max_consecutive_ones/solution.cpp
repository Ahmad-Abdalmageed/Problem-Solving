class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int count = 0;
        int curCount = 0;
        
        for(auto const &num:nums)
        {
            if(num) curCount++;
            else curCount = 0;
            
            count = max(count, curCount);
        }
        
        return count;
    }
};