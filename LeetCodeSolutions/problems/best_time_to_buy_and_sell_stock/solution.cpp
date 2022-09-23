class Solution {
public:
    // Brute == O(n^2)
    // Two Pointers/Sliding Window --- o(n)
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int buy = prices[0];
        
        for(auto const &price: prices)
        {
            buy = std::min(buy, price);
            profit = std::max(profit, price - buy);
        }
        return profit;
    }
};