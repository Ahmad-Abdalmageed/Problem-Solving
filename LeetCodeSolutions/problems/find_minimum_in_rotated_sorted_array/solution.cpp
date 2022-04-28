class Solution {
public:
    // LEETCODE: Find Minimum in Sorted Rotated Array --- ALGORITHM II
    int findMin(vector<int>& nums){
        // Binary Search Algorithm
        int left = 0;
        int rght = nums.size() - 1;
        int res = INT_MAX;


        while(left <= rght){
            // Base Case if Array is Sorted
            if(nums[left] <= nums[rght]){
                res = min(nums[left], res);
                break;
            }
            int mid = left + (rght - left)/2;

            // Update the current Result
            if(nums[mid] < res) res = nums[mid];

            if(nums[mid] >= nums[left]) left = mid + 1;
            else rght = mid - 1;
        }
        return res;
    }
};