class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) 
    {
        std::sort(nums.begin(), nums.end());
        int i = 0, j;
        for( j = 0; j < nums.size(); j++)
        {
            k += nums[j];
            
            if(k < (long)nums[j] * (j - i + 1))
            {
                k -= nums[i];
                i++;
            }
            
        }
        
        return j - i ;
    }
    
    
    
    
    
//     INITIAL THOUGHTS 
//     int maxFrequency(vector<int>& nums, int k)
//     {
//         int first = k;
//         // Sort 
//         std::sort(nums.begin(), nums.end());
//         int res = 0;
        
//         // Using a Sliding window technique
//         int i = 0;
//         int j = 0;
        
//         while(j < nums.size())
//         {
//             int diff = nums[j] - nums[i];
            
//             if(diff <= k)
//             {
//                 res = std::max(res, j - i + 1);
//                 k -= diff;
//             } else {
//                 i = j;
//                 k = first;
//             }
//             j++;            
//         }
        
//         return res;
        
//     }
};