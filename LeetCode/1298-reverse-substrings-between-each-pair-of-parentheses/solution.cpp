class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        unordered_map<int, int> mp;
        stack<int> opens;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                opens.push(i);
            }
            else if (s[i] == ')') {
                int o = opens.top();
                mp[o] = i;
                opens.pop();
            }
        }

        if (mp.empty()) return s;

        string res;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                int c = mp[i];
                string sub = reverseParentheses(s.substr(i + 1, c - i - 1));
                reverse(sub.begin(), sub.end());
                res += sub;
                i = c;
            }
            else res += s[i];
        }

        return res;
    }
};
