class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int fmin = -1;
        int smin = -1;
        int imin = -1;
        int N = costs.size();
        
        for (int i = 0; i < costs[N-1].size(); ++i) {
            if (fmin == -1 || costs[N-1][i] < fmin) {
                smin = fmin;
                fmin = costs[costs.size()-1][i];
                imin = i;
            } else if (smin == -1 || costs[N-1][i] < smin) {
                smin = costs[N-1][i];
            }
        }

        for (int i = costs.size()-2; i >= 0; --i) {
            int next_fmin = -1;
            int next_smin = -1;
            int next_imin = -1;
            for (int j = 0; j < costs[i].size(); ++j) {
                if (j != imin) {
                    costs[i][j] += fmin;
                } else {
                    costs[i][j] += smin;
                }
                if (next_fmin == -1 || costs[i][j] < next_fmin) {
                    next_smin = next_fmin;
                    next_fmin = costs[i][j];
                    next_imin = j;
                } else if (next_smin == -1 || costs[i][j] < next_smin) {
                    next_smin = costs[i][j];
                }
            }
            fmin = next_fmin;
            smin = next_smin;
            imin = next_imin; 
        }
        return fmin;
    }
};
