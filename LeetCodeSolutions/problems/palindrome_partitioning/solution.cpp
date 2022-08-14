class Solution
{
public:
  std::vector<std::vector<std::string>> partition(std::string s);

private:
  std::vector<std::vector<std::string>> result_;
  std::vector<std::string> partition_;
  std::string word_;

  void backtrack(int startIdx);
  bool isPalindrome(std::string word, int leftIdx, int rightIdx);
};

std::vector<std::vector<std::string>> Solution::partition(std::string s)
{
  word_ = std::string(s);
  backtrack(0);
  return result_;
}
void Solution::backtrack(int startIdx)
{
  if (startIdx >= word_.size())
  {
    result_.push_back(partition_);
    return;
  }

  for (int nxtIdx = startIdx; nxtIdx < word_.size(); nxtIdx++)
  {
    if (isPalindrome(word_, startIdx, nxtIdx))
    {
      partition_.push_back(word_.substr(startIdx, nxtIdx - startIdx + 1));
      backtrack(nxtIdx + 1);
      partition_.pop_back();
    }
  }
}
bool Solution::isPalindrome(std::string word, int leftIdx, int rightIdx)
{
  while (leftIdx < rightIdx)
  {
    if (word[leftIdx] != word[rightIdx])
    {
      return false;
    }
    leftIdx++;
    rightIdx--;
  }
  return true;
}
