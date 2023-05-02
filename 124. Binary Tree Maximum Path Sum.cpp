/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        bfs(root, ans);
        return ans;
    }


    int bfs (TreeNode* root, int& global_max) {
       
        if (!root) {
            return 0;
        }

        int lmax = max(0, bfs(root->left, global_max));
        int rmax = max(0, bfs(root->right, global_max));

        int local_max = root->val + lmax + rmax;
        global_max = max(global_max, local_max);
        
        return root->val + max(lmax, rmax);
    }
};
