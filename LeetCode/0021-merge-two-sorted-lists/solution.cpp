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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> a;
        while (list1) {
            a.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2) {
            a.push_back(list2->val);
            list2 = list2->next;
        }
        if (a.empty()) return nullptr;
        sort(a.begin(), a.end());
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int n = a.size();
        for (int i=0; i<n; i++) {
            temp->val = a[i];
            if (i == n-1) continue;
            temp->next = new ListNode();
            temp = temp->next;
        }
        return head;
    }
};
