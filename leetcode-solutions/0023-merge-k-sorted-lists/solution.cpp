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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> vals;
        int n = lists.size();
        for (int i=0; i<n; i++) {
            ListNode* start = lists[i];
            while (start != nullptr) {
                vals.insert(start->val);
                start = start->next;
            }
        }

        if (vals.empty()) return {};

        ListNode *res = new ListNode();
        ListNode *temp = res;
        int m = vals.size();
        int xd = 0;
        for (int i : vals) {
            temp->val = i;
            if (xd != m-1) {
                temp->next = new ListNode();
                temp = temp->next;
            }
            xd++;
        }

        return res;
    }
};
