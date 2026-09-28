class Solution {
public:
    int maxDepth(string s) {
        int a = 0, b=0;
        for (char c : s) {
            if (c == '(') a++;
            if (c == ')') a--;
            b = max(b, a);
        }
        return b;
    }
};
