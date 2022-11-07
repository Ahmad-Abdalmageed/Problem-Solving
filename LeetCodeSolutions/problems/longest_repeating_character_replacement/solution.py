class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counts = {}
        res = 0
        maxFreq = 0

        left = 0

        # Maximumize the number of frequent elements at each window
        for rght in range(len(s)):
            counts[s[rght]] = 1 + counts.get(s[rght], 0)
            maxFreq = max(maxFreq, counts[s[rght]]) #Update the most frequent char

            if (rght - left + 1) - maxFreq > k: # The current window is invalid
                #  Update the Window if invalid 
                counts[s[left]] -= 1
                left += 1
            res = max(res, rght - left + 1)

        return res