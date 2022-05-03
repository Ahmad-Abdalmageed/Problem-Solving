class Solution {
public:
  // LEETCODE:
  int findUnsortedSubarray(vector<int> &nums) {
    // Copy Nums Array into a Sorted Copy
    std::vector<int> numSorted(nums.begin(), nums.end());
    std::sort(numSorted.begin(), numSorted.end());

    // Count Subarray Size 
    int subArrayCount = 0;
    int left = nums.size();
    int rght = 0;
    for(int ptr = 0; ptr<nums.size(); ptr++){
      if(nums[ptr] != numSorted[ptr]){
        left = std::min(left, ptr);
        rght = std::max(rght, ptr);
      }
    }

    return (rght - left >= 0) ? rght-left+1: 0;
  }

};