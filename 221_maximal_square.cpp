class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> nums(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        
        for (int i = nums.size()-2; i >= 0; --i) {
            for (int j = nums[i].size()-2; j >= 0; --j) {

                if (matrix[i][j] == '1') {
                    
                    int tmp = min(nums[i][j+1], nums[i+1][j]);
                    nums[i][j] = min(tmp, nums[i+1][j+1]) + 1;

                    ans = max(ans, nums[i][j]);
                }
            }
        }
        return ans*ans;
    }
};
