class Solution {
    bool comp = false;
    vector<int> dp;
    bool valid(int x) {
        bool changed = false;
        while (x) {
            int d = x % 10;
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) changed = true;
            x /= 10;
        }
        return changed;
    }
public:
    int rotatedDigits(int n) {
        if (!comp) {
            dp.resize(1e4+1);
            dp[0] = 0;
            for (int i=1; i<=1e4; i++) dp[i] = dp[i-1] + valid(i);
            comp = true;
        }
        return dp[n];
    }
};
