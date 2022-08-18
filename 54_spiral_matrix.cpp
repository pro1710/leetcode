class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int r = 0;
        int c = 0;
        
        vector<int> res = {};
        
        bool debug = 0;
        
        while (m > 0 && n > 0) {
            
            // right
            if (n) {
                for (int i = 0; i < n; ++i) {
                    res.push_back(matrix[r][c++]);
                }
                c--;
                m--;
                
                // down
                if (m) {
                    for (int i = 0; i < m; ++i) {
                        res.push_back(matrix[++r][c]);
                    }
                    n--;

                     // left
                    if (n) {
                        for (int i = 0; i < n; ++i) {
                            res.push_back(matrix[r][--c]);
                        }
                        m--;
                        
                        // up
                        if (m) {
                            for (int i = 0; i < m; ++i) {
                                res.push_back(matrix[--r][c]);
                            }
                            c++;
                            --n;
                        }
                    }
                } 
            }
        }
        
       
        
        return res;
    }
};
