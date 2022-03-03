class Solution {
public:
int numberOfArithmeticSlices(vector<int>& nums){
    int SUBSEQ_COUNT = 0;
    int CUMULATIVE_COUNT = 0;
    int DIFF = INT32_MAX;

    if(nums.size() <= 2 ) return 0;
    for(int i = 1; i < nums.size();i++){
        int NEW_DIFF = nums[i] - nums[i-1];
        // Check the last two numbers for the arithmatic sequence
        if(NEW_DIFF == DIFF){
            CUMULATIVE_COUNT += 1 ;
            // Add the cumulative Count to the Result
            SUBSEQ_COUNT += CUMULATIVE_COUNT;

        } else{
            // Restart Cumulative counter when finds a different sequence
            CUMULATIVE_COUNT = 0;
            DIFF = NEW_DIFF;
        }
    }

    return SUBSEQ_COUNT;
}

};