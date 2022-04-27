class Solution {
public:
    // LEETCODE: 33. Search in Rotated Sorted Array
    int search(vector<int>& nums, int target){
        // Discrete Binary Search 
        int left = 0;
        int rght = nums.size()-1;

        // Binary Search
        while(left <= rght){
            int mid = left + (rght - left)/2;

            // Case Found 
            if(target == nums[mid]) return mid;

            // Two Casees : 1 - Left Sorted Portion
            if(nums[left] <= nums[mid]){
                if(target > nums[mid] || target < nums[left]) left = mid + 1 ;
                else rght = mid - 1;
            } else {
                if(target < nums[mid] || target > nums[rght]) rght = mid -1;
                else left = mid + 1;
            }
        }

        // Case Not Found
        return -1;
    }



};