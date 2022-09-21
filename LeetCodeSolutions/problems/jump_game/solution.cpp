class Solution {
public:
    bool canJump(vector<int>& nums);
};


bool Solution::canJump(vector<int>& nums)
{
    int nextJump = 0;
    
    for(int nextStep = 0; nextStep <= nextJump; nextStep++)
    {
        if(nextStep >= nums.size() - 1) return true;
        nextJump = std::max(nextJump, nextStep   + nums[nextStep]);
    }
    
    return nextJump >= nums.size() - 1;
}

