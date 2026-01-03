class Solution {
public:
    int numSub(string s) {
        long long ans=0, cnt=0;
        for (char c : s) {
            if (c == '0') cnt = 0;
            else {
                cnt++;
                ans += cnt;
                ans %= (long long)1e9+7;
            }
        }
        return ans;
    }
};
