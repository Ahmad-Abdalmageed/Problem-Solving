class Solution {
public:
    // LEETCODE: 217 .. Contains Duplicates
    bool containsDuplicate(vector<int>& nums){
      // Use set to insert unique values only
      std::unordered_set<int> hashSet;

      for(auto num : nums){
        if(hashSet.find(num) != hashSet.end()){
          return true;
        }
        hashSet.insert(num);
      }
       return false;
    }

};