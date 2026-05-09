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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    // move fast n+1 steps
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // move both
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // remove node
    ListNode* del = slow->next;
    slow->next = slow->next->next;

    delete del;

    return dummy.next;
}
};
