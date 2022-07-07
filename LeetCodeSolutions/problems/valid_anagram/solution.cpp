class Solution {
public:
  bool isAnagram(string s, string t){
    //  Base Case ... Strings sizes dont match
    if(s.size() != t.size()){
      return false;
    }

    // 26 Alphabet Characters
    std::vector<int> alphabet(26);

    // Count chars in first String
    for(auto sChar: s){
      alphabet[sChar - 'a']++;
    }

    // Remove Equal Counts .... If count is less  than 0 then not identical 
    // Anagrams
    for(auto tChar : t){
      alphabet[tChar - 'a']--;
      if(alphabet[tChar - 'a'] < 0){
        return false;
      }
    }

    return true;
  }

};