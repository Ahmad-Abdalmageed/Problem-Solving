class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // Bucket Sort 
        vector<int> res;
        vector<int> bucket(3, 0);
        for(auto const &num: nums)
        {
            bucket[num]++;
        }
        
        for(int num = 0; num < 3; num++)
        {
            for(int count = 0; count < bucket[num]; count++)
            {
                res.push_back(num);
            }
            
        }
        nums = res;
    }
};