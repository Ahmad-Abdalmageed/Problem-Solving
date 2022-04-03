class Solution {
public:
    void nextPermutation(vector<int>& nums){
        // Find the First Decreasing element from the right 
        int i = nums.size()-2;
        while(i>=0 && nums[i+1]<= nums[i]){
            i--;
        }

        // Find the Element just larger than i, if i exists
        if( i>=0 ){
            int j = nums.size()-1;
            while(nums[j] <= nums[i]){
                j--;
            }

            // Swap both numbers 
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin()+i+1, nums.end());
    }
};