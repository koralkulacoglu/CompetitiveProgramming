class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string cur;

        auto solve = [&]() {
            int n = cur.size();
            if (n <= 1) return;

            vector<char> stk;
            for (char c : cur) {
                if (stk.empty()) stk.push_back(c);
                else {
                    if (x >= y && c == 'b' && stk.back() == 'a') {
                        stk.pop_back();
                        ans += x;
                    }
                    else if (x <= y && c == 'a' && stk.back() == 'b') {
                        stk.pop_back();
                        ans += y;
                    }
                    else stk.push_back(c);
                }
            }

            vector<char> stk2;
            for (char c : stk) {
                if (stk2.empty()) stk2.push_back(c);
                else {
                    if (c == 'b' && stk2.back() == 'a') {
                        stk2.pop_back();
                        ans += x;
                    }
                    else if (c == 'a' && stk2.back() == 'b') {
                        stk2.pop_back();
                        ans += y;
                    }
                    else stk2.push_back(c);
                }
            }
        };

        for (char c : s) {
            if (c == 'a' || c == 'b') cur.push_back(c);
            else {
                solve();
                cur = "";
            }
        }
        solve();

        return ans;
    }
};

