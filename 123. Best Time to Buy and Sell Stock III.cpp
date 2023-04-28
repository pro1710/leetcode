class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int> profit(prices.size(), 0);
        int max_price = prices.back();

        for (int i = prices.size()-2; i >= 0; --i) {
            if (prices[i] > max_price) {
                max_price = prices[i];
            }
            profit[i] = max(profit[i+1], max_price - prices[i]);
        }

        int min_price = prices.front();

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            profit[i] = max(profit[i-1], profit[i] + (prices[i] - min_price));
        }


        return profit.back();


    }
};




// class Solution {
// public:
//     Solution() {
//         ios_base::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);
//     }
//   int maxProfit(vector<int>& prices) {
//         int sold[2] = {}, bought[2] = {INT_MIN, INT_MIN};
//         for (int x : prices) {
//             bought[0] = max(bought[0], -x);
//             sold[0] = max(sold[0], bought[0] + x);
//             bought[1] = max(bought[1], sold[0] - x);
//             sold[1] = max(sold[1], bought[1] + x);
//         }
//         return max(sold[0], sold[1]);
//     }
// };
