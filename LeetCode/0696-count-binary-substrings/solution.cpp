class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        char cur = s[0];
        int prevCnt = 0, curCnt = 1, ans = 0;
        for (int i=1; i<n; i++) {
            if (s[i] == cur) {
                curCnt++;
            }
            else {
                prevCnt = curCnt;
                curCnt = 1;
            }
            ans += (prevCnt >= curCnt);
            cur = s[i];
        }
        return ans;
    }
};
