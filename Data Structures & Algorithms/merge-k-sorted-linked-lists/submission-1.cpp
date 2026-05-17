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

    struct cmp {

        bool operator()(ListNode* a,
                        ListNode* b) {

            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            cmp
        > pq;

        // push all head nodes
        for (ListNode* head : lists) {

            if (head) {

                pq.push(head);
            }
        }

        ListNode dummy(0);

        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // smallest node
            ListNode* node = pq.top();

            pq.pop();

            // add to answer
            tail->next = node;

            tail = tail->next;

            // push next node from same list
            if (node->next) {

                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
