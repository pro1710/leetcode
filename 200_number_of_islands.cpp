class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        stack<pair<int, int>> stk = {};
        int numIslands = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0 ; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    stk.emplace(i, j);
                    grid[i][j] = '*';
                    numIslands++;
                    while (!stk.empty()) {
                        auto coords = stk.top();
                        stk.pop();

                        int& r = coords.first;
                        int& c = coords.second;
                        
                        if (r+1 < grid.size() && grid[r+1][c] == '1') {
                            stk.emplace(r+1, c);
                            grid[r+1][c] = '*';
                        }

                        if (r-1 >= 0 && grid[r-1][c] == '1') {
                            stk.emplace(r-1, c);
                            grid[r-1][c] = '*';
                        }

                        if (c+1 < grid[r].size() && grid[r][c+1] == '1') {
                            stk.emplace(r, c+1);
                            grid[r][c+1] = '*';
                        }
                        
                        if (c-1 >= 0 && grid[r][c-1] == '1') {
                            stk.emplace(r, c-1);
                            grid[r][c-1] = '*';
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};
