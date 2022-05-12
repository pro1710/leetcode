class Solution {
public:
    
    vector<vector<set<char>>> options;
    
    void getOptions(const vector<vector<char>>& board) {
        options.resize(9, {});
        for (auto& row : options) {
			row.resize(9);
        }
        
        set<char> allOptions = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        set<char> result = {};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                for (auto opt: allOptions) {
                    if (valid(board, opt, i, j)) {
                        options[i][j].insert(opt);
                    }
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        getOptions(board);
        solve(board, 0);
    }
    
    bool solve(vector<vector<char>>& board, int r) {
        
        for (int i = r; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                
                const auto& opts = options[i][j];
                for (auto opt: opts) {

                    if (!valid(board, opt, i, j)) {
                        continue;
                    }
                    
                    board[i][j] = opt;

                    if ( solve(board, i) ) {
                        return true;
                    }

                    board[i][j] = '.';
                }
                return false; 
            }
        }         
        return true;
    }
    
    bool valid(const vector<vector<char>>& board, char opt, int r, int c) {
         for (int i = 0; i < board.size(); ++i)
        {
            if (board[i][c] == opt)
                return false;
            if (board[r][i] == opt)
                return false;
            if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == opt)
                return false;
        }
        return true;
    }
};
