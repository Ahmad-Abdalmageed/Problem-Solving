class Solution {
public:
  std::vector<int> findAnagrams(std::string s, std::string p);

private:
  template <typename Map>
  bool compMaps(Map const &leftMap, Map const &rghtMap);
};


std::vector<int> Solution::findAnagrams(std::string s, std::string p) {
  // Base Case Check
  if (p.size() > s.size())
    return {};

  // Initialize both Hashmaps
  std::map<char, int> sCountMap;
  std::map<char, int> pCountMap;

  std::vector<int> res;
  // Count the Frequencies in the First String and add the
  // Frequencies of the First Window in the second string
  int ctr = 0;
  for (auto c : p) {
    pCountMap[c]++;
    sCountMap[s[ctr]]++;
    ctr++;
  }

  // Add the First
  if (compMaps(sCountMap, pCountMap)) {
    res.push_back(0);
  }

  int i = 0;
  for (int j = p.size(); j < s.size(); j++) {
    sCountMap[s[j]]++;
    sCountMap[s[i]]--;

    // Remove the Character if already Reached 0 Counts
    if (sCountMap[s[i]] == 0)
      sCountMap.erase(s[i]);

    // Increment the left ptr to the next position
    i++;

    if (compMaps(sCountMap, pCountMap))
      res.push_back(i);
  }
  return res;
}

template <typename Map>
bool Solution::compMaps(Map const &leftMap, Map const &rghtMap) {
  return leftMap.size() == rghtMap.size() &&
         std::equal(leftMap.begin(), leftMap.end(), rghtMap.begin());
}
