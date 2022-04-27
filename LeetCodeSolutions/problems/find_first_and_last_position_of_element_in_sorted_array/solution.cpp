class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target);

private:
    int binarySearch(std::vector<int> nums, int target, bool leftBias);
};


std::vector<int> Solution::searchRange(std::vector<int>& nums, int target){
    // Call The Binary Search Algorithm Twice
    int left = binarySearch(nums, target, true);
    int rght = binarySearch(nums, target, false);

    return {left, rght};
}


int Solution::binarySearch(std::vector<int> nums, int target, bool leftBias){
    // Regular Binary Search
    int left = 0;
    int rght = nums.size()-1;
    int idx = -1;

    while(left <= rght){
        int mid = left + (rght - left) / 2;

        if(target < nums[mid]) rght = mid - 1;
        else if(target > nums[mid]) left = mid + 1;
        else {
            idx = mid;
            if(leftBias) rght = mid-1;
            else left = mid +1;
        }
    }

    return idx;
}
