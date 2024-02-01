class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> stk; // temp, idx
        for (int i=n-1; i>=0; i--) {
            // pop until you see a number in the stack that's larger
            while (!stk.empty() && stk.top().first <= a[i]) {
                stk.pop();
            }

            if (!stk.empty()) {
                ans[i] = stk.top().second - i;
            }

            stk.push(make_pair(a[i], i));
        } 
        return ans;
    }
};
