class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = 0;
        stack<int> stk;
        stk.push(0);
        for (int i = 0; i < n; ++i) {
            int h = target[i];
            if (h > stk.top()) ans += h - stk.top();
            while (!stk.empty() && stk.top() > h) stk.pop();
            if (stk.top() < h) stk.push(h);
        }
        return ans;
    }
};

