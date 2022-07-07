class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums);
private:
  void backtrack(int setLen, int setFirst, std::vector<int> set);
  int numSize;
  std::vector<std::vector<int>> __subsets;
  std::vector<int> nums;
};


std::vector<std::vector<int>> Solution::subsets(std::vector<int> &nums){
  this->numSize = nums.size();
  this->nums = nums;

  // For every subset in the set call the Backtracking Algorithm
  for(int currSetLen = 0; currSetLen < nums.size()+1; currSetLen++){
    this->backtrack(currSetLen, 0, {});
  }
  return this->__subsets;
}

void Solution::backtrack(int setLen, int setFirst, std::vector<int> set){
  // Base Case when the set reaches setLen
  if(set.size() == setLen){
    this->__subsets.push_back(set);
    return;
  }

  // Loop from First Index to n
  for(int currIdx = setFirst; currIdx < this->numSize; currIdx++){
    set.push_back(this->nums[currIdx]);
    this->backtrack(setLen, currIdx+1, set);
    set.pop_back();
  }
}
