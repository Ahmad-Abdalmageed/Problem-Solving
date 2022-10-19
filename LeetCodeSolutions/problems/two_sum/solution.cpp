class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // store the indices 
        unordered_map<int, int> remainderMap;
        vector<int> solution;
        
        
        for(int indx = 0; indx < nums.size(); indx++)
        {
            int remainder = target - nums[indx];
            
            if(remainderMap.find(remainder) != remainderMap.end())
            {
                solution.push_back(indx);
                solution.push_back(remainderMap[remainder]);
            }
            remainderMap[nums[indx]] = indx;
        }
        
        return solution;
    }
};