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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isMirrored(root->left, root->right);
    }


    bool isMirrored(TreeNode* ltree, TreeNode* rtree) {
        if (ltree == nullptr || rtree == nullptr) {
            return ltree == nullptr && rtree == nullptr;
        }

        return ltree->val == rtree->val 
                && isMirrored(ltree->left, rtree->right) 
                && isMirrored(ltree->right, rtree->left);
    }
};
