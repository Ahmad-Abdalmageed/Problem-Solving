class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 100000;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int sum = nums[i]+nums[r]+nums[l];
                if(sum == target){
 
return sum;
                }
                if(abs(target-sum)<abs(target-closest)){
                    closest = sum;

                }
                if(sum<target){
                    l++;
                }
                if(sum>target){
                    r--;
                }
            }





        }
        return closest;
        
    }
};