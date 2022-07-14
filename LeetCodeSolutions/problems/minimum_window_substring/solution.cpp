class Solution {
public:
  // LEETCODE: 76. Minimum Window Substring
  std::string minWindow(std::string s, std::string t)
  {
    // Using Sliding Window Technique and Hash maps
    std::unordered_map<char, int> tCountMap;

    // Count Chars in T
    for (auto const &tChar : t)
    {
      tCountMap[tChar]++;
    }

    // Window Init
    int leftPtr = 0;
    int rghtPtr = 0;

    int minWindowLen = INT_MAX;
    int minWindowStart = 0;

    // Number of Chars Needed
    int counter = t.size();

    while (rghtPtr < s.size())
    {
      // If is a tChar
      if (tCountMap[s[rghtPtr]] > 0)
      {
        counter--;
      }

      // Else, then this will be negative,
      tCountMap[s[rghtPtr]]--;

      // If found all Needed tChars
      while (counter == 0)
      {
        // if Minimum Window Size
        if (rghtPtr - leftPtr + 1 < minWindowLen)
        {
          minWindowLen = rghtPtr - leftPtr + 1;
          minWindowStart = leftPtr;
        }

        // Then Remove from the window by increasing the count 
        // of negative characters, and shiftin left pointer
        tCountMap[s[leftPtr]]++;
        // if already a tChar increase the counter
        if(tCountMap[s[leftPtr]] > 0){
          counter++;
        }
        leftPtr++;
      }
      rghtPtr++;
    }
    // Found a minimum window
    if(minWindowLen != INT_MAX){
      return s.substr(minWindowStart, minWindowLen);
    }
    return "";
  }

};