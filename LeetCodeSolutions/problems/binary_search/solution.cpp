class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = -1;
        int high = nums.size();
        int low = 0;
        
        while(low < high){
            int mid = (low + high)/2;
            if(target < nums[mid] ){
                high = mid;
            } else if (target > nums[mid]) {
                low = mid+1;
            } else {
                idx = mid;
                break;
            }
        }
        
        return idx;
    }
};