class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Create a Storing set
        nums_set = set()
        for num in nums: 
            if num in nums_set:
                return True
            nums_set.add(num)
        return False