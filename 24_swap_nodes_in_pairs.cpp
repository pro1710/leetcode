// 24_swap_nodes_in_pairs.cpp

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
    ListNode* swap2next(ListNode* node) {
        ListNode* first = node->next;
        ListNode* second = first->next;
        if (!second) 
            return first;
        
        ListNode* target = second->next;
        
        second->next = first;
        first->next = target;
        node->next = second;
        
        return first;
    }
    
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* iter = &dummy;
        while(iter->next) {
            iter = swap2next(iter);
        }
        return dummy.next;
    }
};


