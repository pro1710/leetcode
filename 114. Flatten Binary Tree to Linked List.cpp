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
    void flatten(TreeNode* root) {
        makeFlat(root);
    }

    TreeNode* makeFlat(TreeNode* root) {

        if (!root) {
            return nullptr;
        }

        TreeNode* rightSubTree = root->right;

        TreeNode* res = root;

        TreeNode* leftTail = makeFlat(root->left);
        if (leftTail) {
            root->right = root->left;
            root->left = nullptr;

            leftTail->right = rightSubTree;
            res = leftTail;
        }

        TreeNode* rightTail = makeFlat(rightSubTree);
        if (rightTail) {
            res = rightTail;
        }

        return res;
    }
};
