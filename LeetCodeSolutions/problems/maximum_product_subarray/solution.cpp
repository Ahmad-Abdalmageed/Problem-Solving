class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        
        int numsMax = nums[0];
        int numsMin = nums[0];
        
        for(int num = 1; num < n; num++)
        {
            int temp = numsMax;
            numsMax = std::max(temp * nums[num], std::max(nums[num] * numsMin, nums[num]));
            numsMin = std::min(temp * nums[num], std::min(nums[num] * numsMin, nums[num]));
            
            ans = std::max(ans, numsMax);
        
        }
        
        return ans;
    }
};