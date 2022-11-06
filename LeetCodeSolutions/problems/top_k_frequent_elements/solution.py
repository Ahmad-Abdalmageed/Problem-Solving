class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Create a bucket sort array 
        freqs = [[] for _ in range(len(nums) + 1)]
        counts = {}
        for num in nums:
            counts[num] = 1 + counts.get(num, 0)
        
        for num, freq in counts.items():
            freqs[freq].append(num)
        
        freq_k_elements = []
        for kFreqs in range(len(freqs) - 1, 0, -1):
            for num in freqs[kFreqs]:
                freq_k_elements.append(num)
                if len(freq_k_elements) == k:
                    break
            if len(freq_k_elements) == k:
                break
        return freq_k_elements