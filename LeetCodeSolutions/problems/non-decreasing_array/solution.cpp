class Solution {
public:
    bool checkPossibility(vector<int>& nums){
        int opCount = 0;
        
        for(int i = 1; i < nums.size();i++){
            if(nums[i-1] > nums[i]){
                if(opCount || (i > 1 && i < nums.size()-1) && (nums[i-2] > nums[i] && nums[i+1] < nums[i-1])) 
                    return false;
                opCount += 1;
            }
        }
        return true;
    }

};