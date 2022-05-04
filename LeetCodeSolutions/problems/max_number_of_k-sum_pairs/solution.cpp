class Solution {
public:
  // LEETCODE: 1679. Max Number of K-Sum Pairs
  int maxOperations(vector<int> &nums, int k) {
    // use hashmap to count the frequencies of each number
    std::map<int, int> numCounts;
    for (auto num : nums) {
      numCounts[num]++;
    }

    // Loop the Counts and add to the result
    int res = 0;
    for (auto &numCount : numCounts) {
      if (numCount.first * 2 == k) {
        res += std::floor(numCount.second / 2);
        numCount.second -= (numCount.second / 2) * 2;
      } else {
        int pairCount = std::min(numCount.second, numCounts[k - numCount.first]);
        res += pairCount;
        numCount.second -= pairCount;
        numCounts[k - numCount.first] -= pairCount;
      }
    }
    return res;
  }
};