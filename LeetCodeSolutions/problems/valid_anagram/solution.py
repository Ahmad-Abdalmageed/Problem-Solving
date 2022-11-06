class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Base Case: different Sizes
        if len(s) != len(t):
            return False

        s_counts = [0] *26
        
        for s_chr in s:
            s_counts[ord(s_chr) - ord("a")] += 1

        for t_chr in t:
            s_counts[ord(t_chr) - ord("a")] -= 1

            if s_counts[ord(t_chr) - ord("a")] < 0:
                return False
        
        return True