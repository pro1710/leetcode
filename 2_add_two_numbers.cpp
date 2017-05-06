// 2_add_two_numbers.cpp

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *res = NULL;
        
        int c = 0;
        while(l1 != NULL || l2 != NULL) {
            int sum = c;
        
            if (head == NULL) {
                head = new ListNode(0);
                res = head;
            } else {
                res->next = new ListNode(0);
                res = res->next;
            }
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            res->val = sum%10;
            
            c = sum / 10;
        }
        if (c != 0) {
            res->next = new ListNode(c);
        }
        
        return head;
    }
};
