class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> cols(n, true);
        vector<bool> diag(2*n-1, true);
        vector<bool> adiag(2*n-1, true);
        vector<string> curr(n, string(n, '.'));
        
        bt(ans, 0, cols, diag, adiag, curr, n);
        return ans;
    }


    void bt(vector<vector<string>>& ans, 
            int r, vector<bool>& cols, 
            vector<bool>& diag, vector<bool>& adiag, 
            vector<string>& curr, int n) {

        if (r == n) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (cols[i] && diag[i+r] && adiag[n + r-i-1]) {
                cols[i] = false;
                diag[i+r] = false;
                adiag[n + r-i-1] = false;
                curr[r][i] = 'Q';

                bt(ans, r+1, cols, diag, adiag, curr, n);

                curr[r][i] = '.';
                cols[i] = true;
                diag[i+r] = true;
                adiag[n + r-i-1] = true;
            }
            
        }

    }
};
