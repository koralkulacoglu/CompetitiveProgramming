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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> vals(nums.begin(), nums.end());

        while (vals.find(head->val) != vals.end()) head = head->next;
        
        ListNode* temp = head;
        while (temp->next != nullptr) {
            if (vals.find(temp->next->val) != vals.end()) temp->next = temp->next->next;
            else temp = temp->next;
        }

        return head;
    }
};
