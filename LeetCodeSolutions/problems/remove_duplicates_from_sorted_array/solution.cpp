class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        vector<int>::iterator res = unique(nums.begin(), nums.end());
        nums.erase(res, nums.end());
        return nums.size();
    }
};