class Solution {
public:
    // Using Maps
    std::vector<int> twoSum(vector<int> &nums, int target) {
      std::vector<int> res;
      //  Store Each element and its index
      std::unordered_map<int, int> table;

      for (unsigned int i = 0; i < nums.size(); i++) {
        //  Compute the Complementary
        int comp = target - nums[i];

        // If the Complementary is an element existing in the Array
        // Push the Index of the Current element and index of the Complementary 
        // Element
        if (table.find(comp) != table.end()) {
          res.push_back(i);
          res.push_back(table[comp]);
        }

        // if not in table insert current element 
        table.insert({nums[i], i});
      }

      return res;
    }
};  



