class Solution {
public:
  // LEETCODE: 125. Valid Palindrome
  bool isPalindrome(string s)
  {
    // Using Two Pointers approach
    int i = 0;
    int j = s.size() - 1;

    while(i < j){
      // Check if current character is not an alphanumeric character
      while(!std::isalnum(s[i]) && i < j){
        i++;
      }
      while(!std::isalnum(s[j]) && i < j){
        j--;
      }
      if(std::tolower(s[i]) != std::tolower(s[j])){
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

};