class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int M = grid.size();
        int N = grid.front().size();
        
        int max_area = 0;
        
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        vector<vector<int>> st = {};
        
        for (int i = 0; i < visited.size(); ++i) {
            for (int j = 0; j < visited[i].size(); ++j) {
               
                if (!visited[i][j]) {
                    
                    if (grid[i][j] == 0) {
                        visited[i][j] = true;
                        continue;
                    }
                    
                    visited[i][j] = true;
                    st.push_back({i, j});
                    
                    int area = 0;
                    
                    while (!st.empty()) {

                        int R = st.back()[0];
                        int C = st.back()[1];
                        
                        st.pop_back();
                        area++;
                       
                        //up
                        int r = R-1;
                        if (r >= 0 && !visited[r][C] && grid[r][C] == 1) {
                            visited[r][C] = true;
                            st.push_back({r, C});
                        }
                        //down
                        r = R+1;
                        if (r < grid.size() && !visited[r][C] && grid[r][C] == 1) {
                            visited[r][C] = true;
                            st.push_back({r, C});
                        }
                        //left
                        int c = C-1;
                        if (c >= 0 && !visited[R][c] && grid[R][c] == 1) {
                            visited[R][c] = true;
                            st.push_back({R, c});
                        }
                        //right
                        c = C+1;
                        if (c < grid[R].size() && !visited[R][c] && grid[R][c] == 1) {
                            visited[R][c] = true;
                            st.push_back({R, c});
                        }
                    }
                    max_area = max(area, max_area);
                }
            }
        }
        return max_area;
    }
};
