class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_sell = prices[0]
        max_profit = 0

        for price in prices[1::]:
            min_sell = min(price, min_sell)
            max_profit = max(price - min_sell, max_profit)

        return max_profit