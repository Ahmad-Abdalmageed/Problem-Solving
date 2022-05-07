class Solution {
public:
  // LEETCODE: 132 Pattern --- Daily
  bool find132pattern(vector<int> &nums) {
    // Use a Monotonic Decreasing Stack
    // The Goal is to find a Maximum num[j] while maintaining
    // a Stack where all values are decreasing, also to not lose info
    // track the minimum number before every stack push opertaion
    std::stack<std::pair<int, int>> decStack;
    int curMin = nums[0];


    // Skip the First Element as it is not possible to be the Max Value
    for (int n = 1; n < nums.size(); n++) {
      int num = nums[n];
    
      // Remove , If present, all values before from stack that are smaller than
      // the current num value
      while (!decStack.empty() && num >= decStack.top().first)
        decStack.pop();

      // Target Found, after removing smaller elements we already checked that
      // the current num is smaller than the Stack top, if Present, also check for
      // that num is larger than the min present with stack top
      if (!decStack.empty() && num > decStack.top().second)
        return true;

      decStack.push({num, curMin});
      // Update the Current minimum Value
      curMin = std::min(curMin, num);
    }

    // Target Not Found
    return false;
  }

};
