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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int b, int e) {

        if (b >= e) {
            return nullptr;
        }

        int mid = (b+e)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, b, mid);
        root->right = build(nums, mid+1, e);
        return root;


    }
};
