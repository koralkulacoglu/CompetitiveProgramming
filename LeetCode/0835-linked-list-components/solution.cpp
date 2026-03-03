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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, bool> vals;
        for (int i : nums) vals[i] = true;
        bool connected = false;
        int ans = 0;
        while (head != nullptr) {
            if (vals[head->val]) {
                if (!connected)  {
                    connected = true;
                    ans++;
                }
            }
            else connected = false;
            head = head->next;
        }
        return ans;
    }
};
