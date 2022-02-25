def isMatch(s, p):
    memo = {}
    
    def find(i, j):
        if (i, j) in memo:
            return memo[(i, j)]
        
        if i >= len(s) and j >= len(p):
            return True
        
        if j >= len(p):
            return False
        
        match = (i < len(s)) and (s[i] == p[j] or p[j] == ".") 
        
        if ((j+1) < len(p)) and p[j + 1] == "*":
            memo[(i, j)] = (find(i, j+2)) or (match and find(i+1, j)) 
            return memo[(i, j)]
        
        if match:
            memo[(i, j)] = find(i+1, j+1)
            return memo[(i, j)]
        memo[(i, j)] = False
        return False
        
    return find(0, 0)

# def isMatch(text, pattern):
#     memo = {}
#     def dp(i, j):
#         if (i, j) not in memo:
#             if j == len(pattern):
#                 ans = i == len(text)
#             else:
#                 first_match = i < len(text) and pattern[j] in {text[i], '.'}
#                 if j+1 < len(pattern) and pattern[j+1] == '*':
#                     ans = dp(i, j+2) or first_match and dp(i+1, j)
#                 else:
#                     ans = first_match and dp(i+1, j+1)

#             memo[i, j] = ans
#         return memo[i, j]

#     return dp(0, 0)

if __name__ == '__main__':
    print(isMatch("ab", ".*c"))    