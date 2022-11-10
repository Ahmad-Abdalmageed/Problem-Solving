class Solution:
    def isValid(self, s: str) -> bool:
        pStack = []
        pMap = {"}":"{", "]":"[", ")":"("}

        for p in s:
            if p not in pMap:
                pStack.append(p)
                continue
            
            if not pStack or pStack[-1] != pMap[p]:
                return False
            pStack.pop()
        
        return not pStack