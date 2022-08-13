class Solution
{
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target);

private:
  int target_;
  std::vector<int> candidates_;
  std::vector<std::vector<int>> combinations_;

  void dfs(int curSum, int curIdx, std::vector<int> &curCombination);
};

std::vector<std::vector<int>> Solution::combinationSum2(std::vector<int> &candidates, int target)
{
  target_ = target;
  candidates_ = candidates;
  std::sort(candidates_.begin(), candidates_.end());

  std::vector<int> curCombination;
  dfs(0, 0, curCombination);

  return combinations_;
}

void Solution::dfs(int curSum, int curIdx, std::vector<int> &curCombination)
{
  // Failed Case
  if (curSum > target_)
  {
    return;
  }

  // Base Case Reached Target Sum
  if (target_ == curSum)
  {
    combinations_.push_back(curCombination);
    return;
  }

  for (int startIdx = curIdx; startIdx < candidates_.size(); startIdx++)
  {
    // Skip Duplicate Elements
    if(startIdx > curIdx && candidates_[startIdx] == candidates_[startIdx-1]) {
        continue;
    }
    
    curCombination.push_back(candidates_[startIdx]);
    
    // startIdx + 1 --- >> use current element only once
    dfs(curSum + candidates_[startIdx], startIdx + 1, curCombination);
    curCombination.pop_back();
  }
}