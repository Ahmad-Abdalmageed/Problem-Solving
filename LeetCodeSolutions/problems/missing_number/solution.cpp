class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // Using a Bucket Sort Method
        vector<int> bucket(nums.size() + 1, 0);
        
        // Count each entry in position
        for(auto const &num: nums)
        {
            bucket[num]++;
        }
        
        int res = -1;
        // Return the Zero count Position
        for(int num = 0; num < bucket.size(); num++)
        {
            if(bucket[num] == 0)
            {
                res = num;
                break;
            }
        }
        
        return res;
    }
};