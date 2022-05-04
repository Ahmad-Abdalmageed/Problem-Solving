class Solution {
public:
// LEETCODE: Subarray Product Less than K
int numSubarrayProductLessThanK(vector<int>& nums, int k){
  if(k <= 1) return 0;

  // Increasing Sliding Window
  int subArrayCount = 0;
  int left = 0, prod = 1;
  for(int rght = 0; rght<nums.size();rght++){
    prod *= nums[rght];
    while(prod >= k){
      prod /= nums[left];
      left +=1;
    }
    subArrayCount += rght - left +1;
  }
  return subArrayCount;
}
};