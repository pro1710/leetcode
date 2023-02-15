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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head->next) {
            return head;
        }

        ListNode* anchor = nullptr;
        ListNode* first = head;
        int n = right-left+1;

        while (--left) {
            anchor = first;
            first = first->next;
        }

        ListNode* prev = anchor;
        ListNode* thefirst = first;
        while (n--) {
            ListNode* next = first->next;
            first->next = prev;
            prev = first;
            first = next;
        }

        thefirst->next = first;
        if (anchor) {
            anchor->next = prev;
        } else {
            head = prev;
        }

        return head;

    }
};
