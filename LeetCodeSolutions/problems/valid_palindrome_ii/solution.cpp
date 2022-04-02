class Solution {
public:
    bool validPalindrome(std::string s);
private:
    bool isPalindrome(int left, int rght, std::string s);
};

bool Solution::validPalindrome(std::string s){
    // Two Pointers Approach 
    int left = 0;
    int rght = s.size()-1;

    while(left < rght){
        if(s[left] != s[rght]) return (isPalindrome(left, rght-1, s) || isPalindrome(left+1, rght, s));
        left++;
        rght--;
    }
    // THere is No mismatch in the whole String so 
    return true;
}

bool Solution::isPalindrome(int left, int rght, std::string s){
    bool isPalindrom = true;

    // Two Pointers Approach
    while(left < rght){
        // If Mismatch Return False
        if(s[left] != s[rght]) return !isPalindrom;

        // Advance both Pointers
        left++;
        rght--;
    }
    return isPalindrom;
}
