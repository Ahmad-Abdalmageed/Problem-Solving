class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        products = [1] * len(nums)

        prefix = 1
        for idx, num in enumerate(nums):
            products[idx] = prefix
            prefix *= num

        postfix = 1
        for idx in range(len(nums) -1, -1, -1):
            products[idx] *= postfix
            postfix *= nums[idx]
        return products