class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target)
    {
        vector<int> res; 
        map<int, int> table;

        for(unsigned int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];

            if( table.find(comp) != table.end())
            {
                res.push_back(i);
                res.push_back(table[comp]);
            }


            table.insert({nums[i], i});
        }

        return res;
    }



};  



