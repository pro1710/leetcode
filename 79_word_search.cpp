class Solution {
public:
        
    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.size() * board.front().size() < word.size()) {
            return false;
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (find_word(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool find_word(vector<vector<char>>& board, const string& word, int i, int j, int w) {
        
        bool res = false;
        
        if (board[i][j] != word[w]) {
            return false;
        }
        
        if (w == word.size() - 1) {
            return true;
        }

        board[i][j] = '*';

        // down
        if (!res && i+1 < board.size() && find_word(board, word, i+1, j, w+1)) {
            return true;
        }

        // left
        if (!res && j-1 >= 0 && find_word(board, word, i, j-1, w+1)) {
            return true;
        }

        // up
        if (!res && i-1 >= 0 && find_word(board, word, i-1, j, w+1)) {
            return true;
        }

        // right
        if (!res && j+1 < board[i].size() && find_word(board, word, i, j+1, w+1)) {
            return true;
        }
        board[i][j] = word[w];
        
            
        return res;   
        
        
    }
    
};
