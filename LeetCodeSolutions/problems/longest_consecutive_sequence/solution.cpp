class Solution {
public:
  // LEETCODE: 128. Longest Consecutive Sequence
  int longestConsecutive(vector<int> &nums)
  {
    // Use an unordered set to store the values in nums
    std::unordered_set<int> s;
    for (auto const &num : nums)
    {
      s.insert(num);
    }

    // Longest Sequence length
    int result = 0;
    for (auto const &num : nums)
    {
      if (s.find(num - 1) == s.end())
      {
        int sequence = 1;
        while (s.find(num + sequence) != s.end())
        {
          sequence++;
        }
        result = std::max(result, sequence);
      }
    }
    return result;
  }
};