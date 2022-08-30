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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (!head) {
            return head;
        }
        
        ListNode* last = head;
        int n = 1;
        while (last->next) {
            last = last->next;
            ++n;
        }
        
        k = n-(k%n)-1;
        ListNode* new_last = head;
        for (int i = 0; i < k; ++i) {
            new_last = new_last->next;
        }

        last->next = head;
        head = new_last->next;
        new_last->next = nullptr;
        
        return head;
        
    }
};
