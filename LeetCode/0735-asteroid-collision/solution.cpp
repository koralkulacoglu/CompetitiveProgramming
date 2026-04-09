class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        vector<int> res;
        for (int a : asteroids) {
            if (a > 0) stk.push(a);
            else {
                while (!stk.empty() && stk.top() < abs(a)) stk.pop();
                if (stk.empty()) res.push_back(a);
                if (!stk.empty() && abs(a) == stk.top()) stk.pop();
            }
        }
        vector<int> res2;
        while (!stk.empty()) {
            res2.push_back(stk.top());
            stk.pop();
        }
        int m = res2.size();
        for (int i=m-1; i>=0; i--) res.push_back(res2[i]);
        return res;
    }
};
