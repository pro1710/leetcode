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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return {};
        }
        
        vector<int> path;

        vector<vector<int>> ans;
        dfs(path, ans, root, targetSum);

        return ans;

    }


    void dfs(vector<int>& path, vector<vector<int>>& ans, TreeNode* root, int targetSum) {
        path.push_back(root->val);

        if (!root->left && !root->right) {

            if (targetSum - root->val == 0) {
                ans.push_back(path);
            }
        } else {
            if (root->left) {
                dfs(path, ans, root->left, targetSum - root->val);
            }

            if (root->right) {
                dfs(path, ans, root->right, targetSum - root->val);
            }

        }

        
        path.pop_back();

    }

};
