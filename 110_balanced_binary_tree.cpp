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
    bool isBalanced(TreeNode* root) {
        return getTreeDepth(root) != -1;
    }

    int getTreeDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left_depth = getTreeDepth(root->left);
        if (left_depth == -1) {
            return -1;
        }

        int right_depth = getTreeDepth(root->right);
        if (right_depth == -1) {
            return -1;
        }

        if (abs(left_depth - right_depth) > 1) {
            return -1;
        }

        return max(left_depth, right_depth) + 1;
    }
};
