class Solution {
public:
    int rob(vector<int>& nums){
        int house1 = 0, house2 = 0;

        // [house1 , house2, n, n+1, n+2, ......]
        for(int n: nums){
            int temp = std::max(n+house1, house2);
            house1 = house2;
            house2 = temp;
        }
        return house2;
    }   

};


// class Solution {
// public:
//   int rob(vector<int> &nums);

// private:
//   vector<int> memo;
//   int rRob(vector<int> &nums, int house);
// };




// int Solution::rob(vector<int> &nums)
// {
//   if(nums.size() == 0) return 0;
//   memo = vector<int>(nums.size() + 1, 0);
//   memo[0] = 0;
//   memo[1] = nums[0];

//   for (int house = 1; house < nums.size(); house++)
//   {
//     // Next Profit is --- Rob Current House or Rob Next House and Get Profit of Prev
//     memo[house + 1] = std::max(memo[house], memo[house - 1] + nums[house]);
//   }
//   return memo[nums.size()];

//   // Recursive Top Down Solution
//   // // Add Memoization
//   // memo = vector<int>(nums.size() + 1, -1);

//   // return rRob(nums, nums.size() - 1);
// }

// int Solution::rRob(vector<int> &nums, int house)
// {
//   if (house < 0)
//   {
//     return 0;
//   }

//   // Add Memoization
//   if (memo[house] >= 0)
//   {
//     return memo[house];
//   }

//   // Add Memoization
//   int profit = std::max(nums[house] + rRob(nums, house - 2), rRob(nums, house - 1));
//   memo[house] = profit;

//   return profit;
// }