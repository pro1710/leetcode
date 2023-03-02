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
    bool isValidBST(TreeNode* root) {
        
       return isValidBST(LONG_MIN, LONG_MAX, root);
    }

    bool isValidBST(long lo, long hi, TreeNode* root) {

        if (!root) {
            return true;
        }

        if (root->val <= lo || root->val >= hi) {
            return false;
        }

        bool isValidLeft = !root->left || isValidBST(lo, root->val, root->left);
        bool isValidRight = !root->right || isValidBST(root->val, hi, root->right);
       
        return isValidLeft && isValidRight;
    
    }
};
