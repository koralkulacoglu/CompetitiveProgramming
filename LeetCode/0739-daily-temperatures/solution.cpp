class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> stk; // store index

        for (int i=n-1; i>=0; i--) {
            int temp = temperatures[i];
            int idx = i;
            while (!stk.empty()) {
                int j = stk.top();
                int curTemp = temperatures[j];
                if (curTemp > temp) {
                    idx = j;
                    break;
                }
                stk.pop();
            }

            res[i] = idx - i;
            stk.push(i);
        }

        return res;
    }
};
