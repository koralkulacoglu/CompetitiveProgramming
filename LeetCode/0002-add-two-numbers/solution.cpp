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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* node = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int res = val1 + val2 + carry;

            carry = res / 10;
            node->val = res % 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            if (l1 || l2 || carry) node->next = new ListNode();
            node = node->next;
        }

        return head;
    }
};
