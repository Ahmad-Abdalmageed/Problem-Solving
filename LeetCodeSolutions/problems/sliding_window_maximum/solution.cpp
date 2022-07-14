class Solution {
public:
  // LEETCODE: 239. Sliding Window Maximum
  // Using a Sliding window, Dequeue -> Monotonically decreasing queue
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    if(k == 1) return nums;
    std::deque<int> currentWindowIdxs;
    std::vector<int> windowsMax;

    for (int leftPtr = 0; leftPtr < nums.size(); leftPtr++)
    {
      // Shift Current Window if shifted
      if (leftPtr - k == currentWindowIdxs.front())
        currentWindowIdxs.pop_front();

      // Check Dequeue Back is smaller than current index
      while (!currentWindowIdxs.empty() && nums[currentWindowIdxs.back()] < nums[leftPtr])
        currentWindowIdxs.pop_back();

      // Add Current Index
      currentWindowIdxs.push_back(leftPtr);

      // If current window size is K, add current maximum
      if (leftPtr - k + 1 >= 0)
        windowsMax.push_back(nums[currentWindowIdxs.front()]);
    }

    // O(n)
    return windowsMax;
  }
};