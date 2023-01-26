class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        for (int i = costs.size()-2; i >= 0; --i) {
            
            costs[i][0] += min(costs[i+1][1], costs[i+1][2]);
            costs[i][1] += min(costs[i+1][0], costs[i+1][2]);
            costs[i][2] += min(costs[i+1][0], costs[i+1][1]);
            
        }
        return min(min(costs[0][0], costs[0][1]), costs[0][2]);
    }
};