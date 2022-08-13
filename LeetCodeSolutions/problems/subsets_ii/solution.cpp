class Solution
{
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums);

private:
  std::vector<std::vector<int>> subsets_;
  void backtrack(std::vector<int> &nums, std::vector<int> subset, int curIdx);
};


std::vector<std::vector<int>> Solution::subsetsWithDup(std::vector<int> &nums)
{
  std::sort(nums.begin(), nums.end());
  std::vector<int> subset;

  backtrack(nums, subset, 0);
  return subsets_;
}

void Solution::backtrack(std::vector<int> &nums, std::vector<int> subset, int curIdx)
{
  if (curIdx == nums.size())
  {
    subsets_.push_back(subset);
    return;
  }

  // Choice: Append Element
  subset.push_back(nums[curIdx]);
  backtrack(nums, subset, curIdx + 1);
  subset.pop_back();

  // Choice: Skip Element
  while (curIdx + 1 < nums.size() && nums[curIdx] == nums[curIdx + 1])
  {
    curIdx++;
  }
  backtrack(nums, subset, curIdx + 1);
}
