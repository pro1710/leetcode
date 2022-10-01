class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> distance(mat.size(), vector<int>(mat[0].size(), 0));

        queue<array<int, 2>> q = {};
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dis = 0;
        int res = 0;
        while (!q.empty()) {
            dis++;
            for (int i = 0, e = q.size(); i < e; ++i) {
                auto pos = q.front();
                q.pop();

                int r = pos[0]-1;
                int c = pos[1];
                if (r >= 0 && mat[r][c]) {
                    mat[r][c] = 0;
                    distance[r][c] = dis;
                    q.push({r, c});
                }
                r = pos[0]+1;
                if (r < mat.size() && mat[r][c]) {
                    mat[r][c] = 0;
                    distance[r][c] = dis;
                    q.push({r, c});
                }
                r = pos[0];
                c = pos[1]-1;
                if (c >= 0 && mat[r][c]) {
                    mat[r][c] = 0;
                    distance[r][c] = dis;
                    q.push({r, c});
                }
                c = pos[1]+1;
                if (c < mat[r].size() && mat[r][c]) {
                    mat[r][c] = 0;
                    distance[r][c] = dis;
                    q.push({r, c});
                }
            }
            
        }
        return distance;
    }
};
