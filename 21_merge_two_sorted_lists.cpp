// 21_merge_two_sorted_lists.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }
        
        ListNode* head = NULL;
        if (l1->val > l2->val) {
            head = l2;
            l2 = l2->next;
        } else {
            head = l1;
            l1 = l1->next;
        }
        
        ListNode* iter = head;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                iter->next = l2;
                l2 = l2->next;
            } else {
                iter->next = l1;
                l1 = l1->next;
            }
            iter = iter->next;
        }
        
        if (l1) 
            iter->next = l1;
        else
            iter->next = l2;
            
        return head;
    }
};


