class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = -1e5;
        int hold = -1e5;
        int reset = 0;
        
        for (auto& p: prices) {
            int tmp = sold;
            sold = hold + p;
            hold = max(hold, reset-p);
            reset = max(reset, tmp);   
        }
        return max(sold, reset);
    }
};
