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
    unordered_map<int, int> lookup;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for (int i = 0; i < inorder.size(); ++i) {
            lookup[inorder[i]] = i;
        }

        int p = postorder.size()-1;
        return build(inorder, 0, inorder.size()-1, postorder, p);

    }


    TreeNode* build(vector<int>& inorder, int ib, int ie, vector<int>& postorder, int& p) {

        if (ib > ie) {
            return nullptr;
        } 

        TreeNode* root =  new TreeNode(postorder[p]);
        --p;
        
        if (ib == ie) {
            return root;
        }

        int i = lookup[root->val];
        // for (; i <= ie; ++i) {
        //     if (inorder[i] == root->val) {
        //         break;
        //     }
        // }

        root->right = build(inorder, i+1, ie, postorder, p);

        root->left = build(inorder, ib, i-1, postorder, p);
    
        return root;
    }

};
