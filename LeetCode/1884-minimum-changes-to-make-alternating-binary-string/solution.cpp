class Solution {
public:
    int minOperations(string s) {
        int ops = 0;
        int n = s.size();
        for (int i=0; i<n; i++) ops += (s[i] != (i&1 ? '0' : '1'));
        return min(ops, n - ops);
    }
};
