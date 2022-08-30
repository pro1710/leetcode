class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
       
        // int n = matrix[0].size();
        
        int m = n;
        
        int r = 0;
        int c = 0;
        
        int val = 1;
        
        while (m > 0 && n > 0) {
            
            // right
            if (n) {
                for (int i = 0; i < n; ++i) {
                    matrix[r][c++] = val++;
                }
                c--;
                m--;
                
                // down
                if (m) {
                    for (int i = 0; i < m; ++i) {
                        matrix[++r][c] = val++;
                    }
                    n--;

                     // left
                    if (n) {
                        for (int i = 0; i < n; ++i) {
                            matrix[r][--c] = val++;
                        }
                        m--;
                        
                        // up
                        if (m) {
                            for (int i = 0; i < m; ++i) {
                                matrix[--r][c] = val++;
                            }
                            c++;
                            --n;
                        }
                    }
                } 
            }
        }
        
       
        
        return matrix;
    }
};
