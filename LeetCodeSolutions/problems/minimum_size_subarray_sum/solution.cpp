class Solution {
public:
  // LEETCODE: Minium Size Subarray
  int minSubArrayLen(int target, vector<int> &nums) {
    // Increasing Sliding Window Size
    int left = 0;
    int minSubArrayLen = INT_MAX;
    int sum = 0;
    for(int rght = 0; rght < nums.size(); rght++){
      sum += nums[rght];
      while(sum >= target){
        minSubArrayLen = std::min(minSubArrayLen, rght-left+1);
        sum -= nums[left];
          left += 1;
      }
    }
    return minSubArrayLen == INT_MAX ? 0: minSubArrayLen;
  }

};