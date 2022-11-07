class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = float("-inf")

        left = 0
        rght= len(height) - 1

        while left < rght:
            current_area = min(height[left], height[rght]) * (rght - left)
            max_area = max(max_area, current_area)

            if height[left] < height[rght]:
                left += 1
            else:
                rght -= 1
        return max_area