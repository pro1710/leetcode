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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }

        stack<TreeNode*> zig, zag;
        zig.push(root);
        int level = -1;
        while(!zig.empty() || !zag.empty()) {
            ++level;
            int levelSize = (level % 2) ? zag.size(): zig.size();
            TreeNode* node;
            vector<int> vals;
            for(int i = 0; i < levelSize; ++i) {
                if(level % 2 == 0) {
                    node = zig.top();
                    zig.pop();
                    vals.push_back(node->val);
                    if(node->left) {
                        zag.push(node->left);
                    }
                    if(node->right) {
                        zag.push(node->right);
                    }
                } else {
                    node = zag.top();
                    zag.pop();
                    vals.push_back(node->val);
                    if(node->right) {
                        zig.push(node->right);
                    }
                    if(node->left) {
                        zig.push(node->left);  
                    }                  
                }
            }
            ans.push_back(move(vals));
        }
        return ans;
    }
};
