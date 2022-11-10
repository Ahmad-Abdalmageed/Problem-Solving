class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        
        count_of_t , current_window = {}, {}

        for char in t:
            count_of_t[char] = 1 + count_of_t.get(char, 0)
        
        have, need = 0, len(count_of_t)
        res , res_length = [-1, -1], float("infinity")
        left = 0

        for rght in range(len(s)):
            current_char = s[rght]
            current_window[current_char] = 1 + current_window.get(current_char, 0)

            if current_char in count_of_t and current_window[current_char] == count_of_t[current_char]:
                have += 1 
            
            while have == need:
                if (rght - left + 1) < res_length:
                    res = [left, rght]
                    res_length = rght - left + 1
                current_window[s[left]] -= 1
                if s[left] in count_of_t and current_window[s[left]] < count_of_t[s[left]]:
                    have -= 1
                left += 1
        left, rght = res
        return s[left: rght+1] if res_length != float("infinity") else ""

