class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        left = rght = 0

        substring = set()
        while rght < len(s):
            while s[rght] in substring:
                substring.remove(s[left])
                left += 1
            substring.add(s[rght])
            max_length = max(max_length, rght - left + 1)
            rght += 1
        return max_length