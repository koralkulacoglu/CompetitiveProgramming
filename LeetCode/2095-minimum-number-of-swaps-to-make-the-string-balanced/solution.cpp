class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && stk.top() == '[' && c == ']') stk.pop();
            else stk.push(c);
        }
        return (stk.size() / 2 + 1) / 2;
    }
};
