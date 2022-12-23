class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<array<int, 2>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1}, 
            {0, -1}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        int N = grid.size();

        vector<vector<int>> dis(N, vector<int>(N, 0));

        queue<array<int, 2>> q = {};
        if (grid[N-1][N-1] == 0) {
            q.push({N-1, N-1});
            dis[N-1][N-1] = 1;
        }
        
        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (auto& [i, j]: dir) {
                int R = r+i;
                int C = c+j;
                if (R < N && C < N && R >= 0 && C >= 0 && grid[R][C] == 0 && dis[R][C] == 0) {
                    dis[R][C] = dis[r][c] + 1;
                    q.push({R, C});
                }
            }

        }
        return dis[0][0] ? dis[0][0] : -1;
    }
};
