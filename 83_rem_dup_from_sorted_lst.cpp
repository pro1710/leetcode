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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* nxt = curr;
        while (nxt) {
            if (curr->val != nxt->val) {
                if (curr->next != nxt) {
                    curr->next = nxt;
                } 
                curr = nxt;
            }
            nxt = nxt->next;
        }
        if (curr) {
            curr->next = nxt;
        }
        
        
        return head;
    }
};
