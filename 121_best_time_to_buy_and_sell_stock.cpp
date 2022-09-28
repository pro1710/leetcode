class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices.front();
        int profit = 0;
        for (int i = 1; i < prices.size();++i) {
            if (min_price > prices[i]) {
                min_price = prices[i];
            } 
            profit = max(profit, prices[i]-min_price);
        }
        return profit;
    }
};
