class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        std::unordered_map<int, int> countMap;
        
        for(auto const &num: nums)
        {
            countMap[num]++;
        }
        
        int res = -1;
        for(auto const &count: countMap)
        {
            if(count.second > nums.size() / 2)
            {
                res = count.first;
                break;
            } 
        }
        return res;

    }

};