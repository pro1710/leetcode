class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_count = 0;
        queue<array<int, 2>> q = {};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        if (!fresh_count) {
            return 0;
        }

        int days = 0;
        while (!q.empty()) {
            days++;
            for (int i = 0, e = q.size(); i < e; ++i) {
                auto pos = q.front();
                q.pop();

                int r = pos[0]-1;
                int c = pos[1];
                if (r >= 0 && grid[r][c]==1) {
                    grid[r][c] = 2;
                    fresh_count--;
                    q.push({r, c});
                }
                r = pos[0]+1;
                if (r < grid.size() && grid[r][c]==1) {
                    grid[r][c] = 2;
                    fresh_count--;
                    q.push({r, c});
                }
                r = pos[0];
                c = pos[1]-1;
                if (c >= 0 && grid[r][c]==1) {
                    grid[r][c] = 2;
                    fresh_count--;
                    q.push({r, c});
                }
                c = pos[1]+1;
                if (c < grid[r].size() && grid[r][c]==1) {
                    grid[r][c] = 2;
                    fresh_count--;
                    q.push({r, c});
                }
            }
        }
        
        if (fresh_count) {
            return -1;
        }
        return days-1;
    }
};
