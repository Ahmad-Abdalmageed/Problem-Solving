class Solution 
{
public:
  int countSubstrings(string s);

private:
  int _count;
  void isPalindrome(string s, int left, int rght);
};


int Solution::countSubstrings(string s)
{
  if (s.size() == 1)
    return 1;

  for (int i = 0; i < s.size(); i++)
  {
    // Check for Odd Case
    isPalindrome(s, i, i);

    // Check for Even Case
    isPalindrome(s, i, i + 1);
  }

  return _count;
}

void Solution::isPalindrome(string s, int left, int rght)
{
  while (left >= 0 && rght < s.size() && s[left] == s[rght])
  {
    left--;
    rght++;
    _count++;
  }
}
