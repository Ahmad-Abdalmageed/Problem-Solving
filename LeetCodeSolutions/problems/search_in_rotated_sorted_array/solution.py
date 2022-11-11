class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        rght = len(nums) - 1

        while left <= rght :
            middle = left + ((rght - left )// 2)

            if nums[middle] == target:
                return middle

            if nums[left] <= nums[middle]:
                if target > nums[middle] or target < nums[left]:
                    left = middle + 1
                else: 
                    rght = middle -1 
            else:
                if target < nums[middle] or target > nums[rght]:
                    rght = middle - 1 
                else:
                    left = middle + 1
                    
        return -1
