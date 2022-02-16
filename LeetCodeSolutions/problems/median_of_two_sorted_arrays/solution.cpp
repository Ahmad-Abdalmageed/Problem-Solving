class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //  Swapping Arrays to search the smaller array always 
        if(nums2.size() < nums1.size()){
            vector<int> temp = nums2;
            nums2 = nums1;
            nums1 = temp;
        }

        int lo = 0;
        int hi = nums1.size();
        int totSize = nums1.size() + nums2.size();

        while(lo <= hi){
            int partX = (lo + hi) / 2 ;
            int partY = ((totSize + 1) / 2) - partX;


            // Calculate Left and Right Partitions (Elements) of both arrays 
            int lX = getMax(nums1, partX);
            int rX = getMin(nums1, partX);

            int lY = getMax(nums2, partY);
            int rY = getMin(nums2, partY);

            // Check Median Condition == LeftX <= Righty and Lefty <= RightX
            if((lX <= rY) && (lY <= rX)){
                //  Even Case Return Average
                if(totSize %2 == 0){
                    return (max(lX, lY) + min(rX, rY)) / 2.0;
                } else {
                    return max(lX, lY);
                }
            }

            //  Shifting the partitioning Point
            if(lX > rY){
                hi = partX -1;
            } else {
                lo = partX +1;
            }
        }
        // Not Sorted Case, Search Failed
        return -1;

    }

    int getMax(vector<int> nums, int part){
        if(part == 0){
            return numeric_limits<int>::min();
        } else {
            return nums[part-1];
        }
    }
    int getMin(vector<int> nums, int part){
        if(part == nums.size()){
            return numeric_limits<int>::max();
        } else {
            return nums[part];
        }
    }
};