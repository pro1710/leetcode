class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int balance = prices.front();
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            
            profit = max(profit, prices[i] - balance - fee);
            balance = min(balance, prices[i] - profit);

        }
        return profit;
    }
};
