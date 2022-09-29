class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int balance = -prices.front();
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            
            profit = max(profit, balance + prices[i] - fee);
            balance = max(balance, profit - prices[i]);

        }
        return profit;
    }
};
