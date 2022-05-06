class Solution {
public:
// LEETCODE: Remove All Adjancent Duplicates in String II -- Daily
string removeDuplicates(string s, int k) {
  // Using Stack DS
  std::stack<std::pair<char, int>> charCountStack;

  // For Every Character in the String, add it to stack and
  // Increment its count
  for (auto c : s) {
    if (!charCountStack.empty() && charCountStack.top().first == c)
      charCountStack.top().second += 1;
    else
      charCountStack.push({c, 1});
    
    if(charCountStack.top().second == k) charCountStack.pop();
  }

  std::string res = "";
  while(!charCountStack.empty()){
    char c = charCountStack.top().first;
    int count = charCountStack.top().second;
    charCountStack.pop();
    res = std::string(count, c) + res;
  }
  return res;
}
};