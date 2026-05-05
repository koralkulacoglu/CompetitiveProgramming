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
        if (!head) return head;
        int n = 1;
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
            n++;
        }
        k %= n;
        if (!k) return head;
        temp->next = head;
        for (int i=0; i<n-k; i++) temp = temp->next;
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        return newHead;
    }
};
