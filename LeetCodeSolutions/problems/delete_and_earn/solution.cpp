class Solution {
public:
int deleteAndEarn(vector<int>& nums){
    map<int, int> NUM_FREQ;
    for(auto num: nums){
        if(NUM_FREQ.find(num)==NUM_FREQ.end()){
            NUM_FREQ.insert({num, 1});
        } else {
            NUM_FREQ[num] += 1;
        }
    }
    
    // Sort and remove duplicates 
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int PRE_EARN = 0;
    int CUR_EARN = 0;

    for(int i = 0; i < nums.size(); i++){
        int POINTS = nums[i] * NUM_FREQ[nums[i]];

        if(i > 0 && (nums[i] == nums[i-1] + 1) ){
            int temp = CUR_EARN;
            CUR_EARN = max(PRE_EARN + POINTS, CUR_EARN);
            PRE_EARN = temp;
        } else {
            int temp = CUR_EARN;
            CUR_EARN = CUR_EARN + POINTS;
            PRE_EARN = temp;
        }
    }
    return CUR_EARN;
}
};