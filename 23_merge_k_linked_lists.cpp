// 23_merge_k_linked_lists.cpp

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
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        if (!a) {
            return b;
        } else if (!b) {
            return a;
        }
        
        if (a->val > b->val) {
            b->next = merge2Lists(a, b->next);
            return b;
        } else {
            a->next = merge2Lists(a->next, b);
            return a;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        for (int s = lists.size(); s > 1; s = (s+1)/2) {
            for (int i = 0; i < s/2; ++i) {
                lists[i] = merge2Lists(lists[i], lists[s-i-1]);
            }
        }
        return lists.front();
    }
};


