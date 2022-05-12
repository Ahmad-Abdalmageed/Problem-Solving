class Solution {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums);

private:
  std::map<int, int> numCount;
  std::vector<std::vector<int>> results;
  int combSize;
  void backtrack(std::vector<int> curComb);
};

std::vector<std::vector<int>>
Solution::permuteUnique(std::vector<int> &nums) {
  // Count the Occurencies of each number
  for (auto num : nums) {
    this->numCount[num]++;
  }
  this->combSize = nums.size();
  this->backtrack({});
  return this->results;
}
void Solution::backtrack(std::vector<int> curComb) {
  // Base Case: Reached Maximum Combination Size
  if (curComb.size() == this->combSize) {
    this->results.push_back(curComb);
    return;
  }

  // BackTrack the Problem
  for (auto &[num, count] : this->numCount) {
    if (count > 0) {
      curComb.push_back(num);
      this->numCount[num]--;
      this->backtrack(curComb);

      curComb.pop_back();
      this->numCount[num]++;
    }
  }
}