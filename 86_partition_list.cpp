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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode sentinel(-1, head);
        
        ListNode* p = &sentinel;
        ListNode* prev = nullptr; 
        ListNode* curr = head;
        
        while (curr) {
  
            if (curr->val < x) {
                if (prev) {
                    prev->next = curr->next;
                    curr->next = p->next;
                    p->next = curr;
                    p = curr;
                    curr = prev->next;
                } else {
                    p->next = curr;
                    p = curr;
                    curr = curr->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return sentinel.next;
    }
};
