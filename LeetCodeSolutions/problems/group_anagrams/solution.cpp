class Solution {
public:
  // LEETCODE: 49 .. Group Anagrams
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    std::unordered_map<string, std::vector<std::string>> mp;
    std::vector<std::vector<std::string>> res;

    //  Sort each String and Create a Key Mapping
    for (auto const &str : strs)
    {
      std::string copyStr = str;
      std::sort(copyStr.begin(), copyStr.end());
      mp[copyStr].push_back(str);
    }
    
    // Reserve places for created keys
    res.reserve(mp.size());
    for (auto const &mpItr : mp)
    {
      res.push_back(mpItr.second);
    }
    return res;
  }
};