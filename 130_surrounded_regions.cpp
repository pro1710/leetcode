class Solution {
public:
    void solve(vector<vector<char>>& board) {

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[r].size(); ++c) {
                if (board[r][c] == 'O') {
                    visit(r, c, board);
                }
            }
        }

        for (auto& rs: board) {
            for (auto &cs: rs) {
                if (cs == 'S') {
                    cs = 'O';
                }
            }
        }
    }

    void visit(int R, int C, vector<vector<char>>& board) {

        array<array<int, 2>, 4> dir = {{
            {-1, 0}, 
            {0, -1}, 
            {0, 1},
            {1, 0}
        }};

        queue<array<int, 2>> q = {};
        q.push({R, C});

        vector<array<int, 2>> path = {};
        bool safe = false;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            path.push_back({r, c});

            for (auto& [i, j]: dir) {
                int ri = r+i;
                int ci = c+j;

                if (ri < board.size() && ri >=0 && ci < board[ri].size() && ci >= 0 && board[ri][ci] != 'S') {
                    if (board[ri][ci] == 'O') {
                        board[ri][ci] = 'W';
                        q.push({ri, ci});
                    }
                } else {
                    safe = true;
                    break;
                }
            }
        }

        for (auto& [r, c]: path) {
            board[r][c] = safe ? 'S' : 'X';
        }
    }
};
