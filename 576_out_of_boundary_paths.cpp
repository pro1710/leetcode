class Solution {
    int memo[51][52][51][2];
    const int wrap = (1e9)+7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        if ((startRow == -1 || startRow == m || startColumn == -1 || startColumn == n)) {
            return 1;
        } else if (maxMove == 0) {
            return 0;
        }

        if (memo[startRow][startColumn][maxMove][0]) {
            return memo[startRow][startColumn][maxMove][1];
        }

        int ans = findPaths(m, n, maxMove-1, startRow-1, startColumn); // up

        ans += findPaths(m, n, maxMove-1, startRow+1, startColumn); // down
        ans %= wrap;   

        ans += findPaths(m, n, maxMove-1, startRow, startColumn-1); // left
        ans %= wrap;
        

        ans += findPaths(m, n, maxMove-1, startRow, startColumn+1); // right
        ans %= wrap;
        
        memo[startRow][startColumn][maxMove][0] = true;
        memo[startRow][startColumn][maxMove][1] = ans;

        return ans;
    }

};
