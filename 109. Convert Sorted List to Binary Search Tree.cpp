/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {

        int n = 0;
        ListNode* h = head;
        while(h) {
            ++n;
            h = h->next;
        }

        return construct(&head, n);

    }

    TreeNode* construct(ListNode** pphead, int n) {
        if (n <= 0) {
            return nullptr;
        }

        TreeNode* left = construct(pphead, n/2);

        TreeNode* root = new TreeNode((*pphead)->val);
        root->left = left;

        *pphead = (*pphead)->next;
        root->right = construct(pphead, n - n/2 -1);

        return root;
    }


};
