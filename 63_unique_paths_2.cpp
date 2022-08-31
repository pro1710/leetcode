class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        vector<vector<unsigned>> ans(obstacleGrid.size(), vector<unsigned>(obstacleGrid.front().size(), 0));
        for (int i = 0 ; i < ans.size(); ++i) {
            for (int j = 0; j < ans[i].size(); ++j) {
                ans[i][j] = obstacleGrid[i][j];
            }
        } 
        
        for (int i = ans.size()-1; i >= 0; --i) {
            for (int j = ans[i].size()-1; j >= 0; --j) {
                
                if (ans[i][j] == 1) {
                    ans[i][j] = 0;
                    continue;
                }
                
                if (i == ans.size() - 1) {
                    if (j == ans[i].size()-1) {
                            ans[i][j] = 1;
                    } else {
                        ans[i][j] = ans[i][j+1];
                    }
                } else if (j == ans[i].size()-1) {
                    ans[i][j] = ans[i+1][j];
                } else {
                    ans[i][j] = ans[i+1][j] + ans[i][j+1];
                }
            }
        }
        
        return ans[0][0];
    }
};
