class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        rght = len(s) - 1

        while left < rght:
            while left < rght and not (s[left].isalpha() or s[left].isnumeric()): 
                left += 1
            while left < rght and not (s[rght].isalpha() or s[rght].isnumeric()): 
                rght -= 1

            if s[left].lower() != s[rght].lower(): return False

            left += 1
            rght -= 1
        
        return True