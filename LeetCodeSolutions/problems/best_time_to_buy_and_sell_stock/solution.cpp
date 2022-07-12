class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Using Sliding Window and Two Pointers 
        int maxProfit = 0;
        int minValue = prices[0]; // Use the Most minimum value as theBuy Value 
        
        for(auto const & price: prices){
            minValue = std::min(price, minValue);
            maxProfit = std::max(maxProfit, price - minValue); // Calculate the Profit
        }
        
        return maxProfit;
        
        
    }
};