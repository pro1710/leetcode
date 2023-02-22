class Solution {
public:
    int totalNQueens(int n) {
        int ans{0};
        vector<bool> cols(n, true);
        vector<bool> diag(2*n-1, true);
        vector<bool> adiag(2*n-1, true);

        bt(ans, 0, cols, diag, adiag, n);
        return ans;
    }


    void bt(int& ans, 
            int r, vector<bool>& cols, 
            vector<bool>& diag, vector<bool>& adiag, 
            int n) {

        if (r == n) {
            ++ans;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (cols[i] && diag[i+r] && adiag[n + r-i-1]) {
                cols[i] = false;
                diag[i+r] = false;
                adiag[n + r-i-1] = false;

                bt(ans, r+1, cols, diag, adiag, n);

                cols[i] = true;
                diag[i+r] = true;
                adiag[n + r-i-1] = true;
            }
        }
    }
};
