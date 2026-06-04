class Solution {
    int score(int x) {
        int ans = 0;
        string sx = to_string(x);
        int n = sx.size();
        for (int i=1; i<n-1; i++) {
            int prev = sx[i-1] - '0';
            int cur = sx[i] - '0';
            int nxt = sx[i+1] - '0';
            ans += (cur > prev && cur > nxt);
            ans += (cur < prev && cur < nxt);
        }
        return ans;
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i=num1; i<=num2; i++) {
            ans += score(i);
        }
        return ans;
    }
};
