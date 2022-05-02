class Solution {
public:
  // LEETCODE: 905. Sort Array By Parity -- DAILY
  vector<int> sortArrayByParity(vector<int> &nums) {
    // Two Pointer Approach one pass
    int i = 0;
    int j = 0;

    while(j < nums.size()) {
      // Find even Numbers and bring them forward
      if(nums[j] % 2 == 0){
        std::swap(nums[i], nums[j]);
        i++;
      }

      // Move
      j++;
    }
    return nums;
  }

};