class Solution {
public:
  int rob(vector<int> &nums);

private:
  vector<int> memo;
  int houseRobber(vector<int> &nums, int start, int end);
};

int Solution::rob(vector<int> &nums)
{
  if (nums.size() == 0)
    return 0;
  if (nums.size() == 1)
    return nums[0];
  if (nums.size() == 2)
    return std::max(nums[0], nums[1]);

  int houses = nums.size();

  int profitI = houseRobber(nums, 0, houses - 2);
  int profitII = houseRobber(nums, 1, houses - 1);

  return std::max(profitI, profitII);
}

int Solution::houseRobber(vector<int> &nums, int start, int end)
{
  if (start == end)
    return nums[start];

  memo = vector<int>(nums.size(), 0);
  memo[start] = nums[start];
  memo[start + 1] = std::max(nums[start], nums[start + 1]);

  for (int house = start + 2; house <= end; house++)
  {
    // Next Profit is --- Rob Current House or Rob Next House and Get Profit of Prev
    memo[house] = std::max(memo[house - 1], memo[house - 2] + nums[house]);
  }
  return memo[end];
}
