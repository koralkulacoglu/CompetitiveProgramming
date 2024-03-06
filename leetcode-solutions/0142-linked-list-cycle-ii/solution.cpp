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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, bool> seen;
        while (head != nullptr) {
            if (seen[head]) return head;
            seen[head] = true;
            head = head->next;
        }
        return nullptr;
    }
};
