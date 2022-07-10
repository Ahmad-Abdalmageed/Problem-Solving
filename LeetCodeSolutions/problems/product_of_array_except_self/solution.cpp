class Solution {
public:
  // LEETCODE 238. Product of Array Except Self
  std::vector<int> productExceptSelf(std::vector<int> &nums)
  {
    std::vector<int> res(nums.size(), 1);

    // Prefix Run
    int preFix = 1;
    for(int i = 0; i < res.size();i++){
      res[i] = preFix;
      preFix *= nums[i];
    }

    // Postfix Run
    int posFix = 1;
    for(int i = nums.size()-1; i >= 0 ; i--){
      res[i] *= posFix;
      posFix *= nums[i];
    }
    return res;
  }

};