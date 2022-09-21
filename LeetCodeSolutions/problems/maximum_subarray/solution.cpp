class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int curMax = nums[0];
        int res = nums[0];
        
        for(int num = 1; num < nums.size(); num++)
        {
            curMax = std::max(curMax + nums[num], nums[num]);
            res = std::max(curMax, res);
        }
        
        return res;
    }
};