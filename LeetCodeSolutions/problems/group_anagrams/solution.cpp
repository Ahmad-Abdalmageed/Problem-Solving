class Solution {
public:
  string getKey(string str)
  {
      vector<int> counts(26);
      for(auto const character: str)
      {
          counts[character - 'a']++;
      }
      
      string key = "";
      for(auto const count: counts)
      {
          key.append(to_string(count + 'a'));
      }
      return key;
  }
    
    
  // LEETCODE: 49 .. Group Anagrams
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    std::unordered_map<string, std::vector<std::string>> mp;
    std::vector<std::vector<std::string>> res;

    //  Sort each String and Create a Key Mapping
    for (auto const &str : strs)
    {
      std::string copyStr = str;
      string key = getKey(str);
      mp[key].push_back(str);
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