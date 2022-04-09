class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> counts;
        std::vector<std::vector<int>> freq(nums.size()+1);
        std::vector<int> res;
        // count the frequencies of each item in the list
        for(auto num: nums) counts[num] += 1;
        // add the frequencies to the bucket sort list
        for(auto it: counts)
            freq[it.second].push_back(it.first);
        
        //append to result the most frequent element
        for(int i= freq.size()-1; i>=0; i--){
            for(auto num: freq[i]){
                res.push_back(num);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;
    }
};