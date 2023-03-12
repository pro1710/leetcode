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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int > lookup;
        for (int i = 0; i < inorder.size(); i++) {
            lookup[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size(), lookup);
    }

    TreeNode* build(vector<int>& preorder, int pb, int pe, 
                    vector<int>& inorder, int ib, int ie, 
                    unordered_map<int, int >& lookup) {

        if (pb >= pe) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pb]);

        int ix = lookup[preorder[pb]];
        // for (; ix < ie; ++ix) {
        //     if (preorder[pb] == inorder[ix]) {
        //         break;
        //     }
        // }

        root->left = build(preorder, pb+1, pb + ix-ib + 1, inorder, ib, ix, lookup);
        root->right = build(preorder, pb + ix-ib + 1, pe, inorder, ix+1, ie, lookup);
        return root;

    }

};
