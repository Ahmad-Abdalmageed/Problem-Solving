class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums){
        vector<int> res;
        int left = 0;
        int rght = nums.size()-1;

        while(left <= rght){
            if(abs(nums[rght]) > abs(nums[left])){
                res.push_back( (nums[rght]) * nums[rght] );
                rght--;
            }
            if(abs(nums[rght]) <= abs(nums[left])){
                res.push_back( (nums[left]) * nums[left]);
                left++;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

};