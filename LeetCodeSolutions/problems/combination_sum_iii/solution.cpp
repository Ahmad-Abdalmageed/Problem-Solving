class Solution {
public:
  std::vector<std::vector<int>> combinationSum3(int k, int n);

private:
  int combSize;
  std::vector<std::vector<int>> resComb;

  void backtrack(std::vector<int> curList, int curSum);
};

void Solution::backtrack(std::vector<int> curList, int curSum) {
  // Base Case: Reached Maximum allowed elements and sum is target
  if (curList.size() == this->combSize && curSum == 0) {
    this->resComb.push_back(curList);
    return;
  }
  if (curList.size() < this->combSize) {
    // Try All possible Combinations
    for (int num = curList.empty() ? 1: curList.back() + 1; num <= 9; num++) {
      curList.push_back(num);
      // Exit unnecessary combinations
      if(curSum - num < 0) break;
      this->backtrack(curList, curSum - num);
      curList.pop_back();
    }
  }
  // else { // Skip adding All elements}
}

std::vector<std::vector<int>> Solution::combinationSum3(int k, int n) {
  // Use Backtracking and Recursion to find all possible combinations
  this->combSize = k;
  this->backtrack({}, n);

  // check
  return (this->resComb.empty()) ? std::vector<std::vector<int>>()
                                 : this->resComb;
}
