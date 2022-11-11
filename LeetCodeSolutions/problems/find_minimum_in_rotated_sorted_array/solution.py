class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        rght = len(nums) - 1
        res = nums[0]

        while left <= rght:
            # Sorted Array 
            if nums[left] < nums[rght]:
                res = min(res, nums[left])
                break
            
            middle = left + (rght - left)//2
            res = min(res, nums[middle])

            if nums[left] <= nums[middle]:
                left = middle + 1
            else:
                rght = middle - 1

        return res
