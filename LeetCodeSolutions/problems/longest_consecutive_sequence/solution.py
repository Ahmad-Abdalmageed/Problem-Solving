class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Convert to a set
        numSet = set(nums)
        longest_sequence = 0

        for num in nums:

            # is current number a start of a sequence 
            if (num - 1) not in numSet:
                sequence = 1
                while num + sequence in numSet:
                    sequence += 1
                longest_sequence = max(longest_sequence, sequence)
        
        return longest_sequence