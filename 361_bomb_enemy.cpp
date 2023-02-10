class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        
        vector<vector<int>> hor(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); ++i) {
            int enemies = 0;
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 'E') {
                    enemies++;
                } else if (grid[i][j] == 'W') {
                    int b = j-1;
                    while (b >= 0 && grid[i][b] != 'W') {
                        if (grid[i][b] == '0') {
                            hor[i][b] = enemies;
                        }
                        --b;
                    }
                    enemies = 0;
                }
            }

            int b = grid[0].size()-1;
            while (b >= 0 && grid[i][b] != 'W') {
                if (grid[i][b] == '0') {
                    hor[i][b] = enemies;
                }
                --b;
            }
        }

        int ans = 0;
        for (int j = 0; j < grid[0].size(); ++j) {
            int enemies = 0;
            for (int i = 0; i < grid.size(); ++i) {
                if (grid[i][j] == 'E') {
                    enemies++;
                } else if (grid[i][j] == 'W') {
                    int b = i-1;
                    while (b >= 0 && grid[b][j] != 'W') {
                        if (grid[b][j] == '0') {
                            ans = max(ans, enemies + hor[b][j]);
                        }
                        --b;
                    }
                    enemies = 0;
                }
            }

            int b = grid.size()-1;
            while (b >= 0 && grid[b][j] != 'W') {
                if (grid[b][j] == '0') {
                    ans = max(ans, enemies + hor[b][j]);
                }
                --b;
            }

        }

        return ans;
    }
};
