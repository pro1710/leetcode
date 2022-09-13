class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
   
        int r = 0;
        for (; r < matrix.size(); ++r) {
            if (matrix[r][0] > target) {
                break;
            }
        } 
        r = max(0, r-1);
        
        return find(begin(matrix[r]), end(matrix[r]), target) != end(matrix[r]);
        
//         int m = matrix.size();
//         int n = begin(matrix)->size();
        
//         int low = 0;
//         int high = m*n-1;
        
//         while (low <= high) {
            
//             int mid = low + (high - low) / 2;
//             int r = mid / n;
//             int c = mid % n;
            
//             if (matrix[r][c] == target) {
//                 return true;
//             } 
            
//             if (matrix[r][c] > target) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
            
//         }
        
//         return false;
    }
};
