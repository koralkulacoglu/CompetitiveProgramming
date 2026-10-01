class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else return false;
            }
            else if (c == '}') {
                if (!stk.empty() && stk.top() == '{') stk.pop();
                else return false;
            }
            else if (c == ']') {
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else return false;
            }
            else stk.push(c);
        }
        return stk.empty();
    }
};
