class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        comps_dict = {}

        for idx, num in enumerate(nums):
            comp = target - num
            if comp in comps_dict:
                return [idx, comps_dict[comp]]
            comps_dict[num] = idx
        