class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res;
        while(true){
            int count = 0;
            int idx = rand() % nums.size();
            for(auto num: nums){
                if(num == nums[idx]) count++;
            }
            if(count > nums.size()/2){
                return nums[idx];
            }

        }
    }

};