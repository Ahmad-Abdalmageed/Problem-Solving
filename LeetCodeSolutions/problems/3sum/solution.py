class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        triplets = []
        nums.sort()

        for k in range(len(nums)):
            # Check for duplicate pointers
            if k > 0 and nums[k] == nums[k-1]:
                continue

            #  Two Pointers Approach
            i = k + 1
            j = len(nums) - 1
            
            while i < j:
                target = nums[i] + nums[k] + nums[j]

                if target < 0:
                    i += 1
                elif target > 0:
                    j -= 1
                else:
                    triplets.append([nums[i], nums[j], nums[k]])
                    i += 1
                    while nums[i] == nums[i-1] and i < j:
                        i += 1
        return triplets

