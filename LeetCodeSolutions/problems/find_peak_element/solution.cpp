class Solution {
public:
    // LEETCODE: Find Peak Element --- ALGORITHMS II
    int findPeakElement(vector<int>& nums){
        // Binary Search Algorithm
        int left = 0;
        int rght = nums.size()-1;

        while(left < rght){
            int mid = left + (rght - left)/2;

            // Find Peak
            if(nums[mid] > nums[mid+1]) rght = mid;
            else left = mid + 1;
        }
        return left;

    }

};