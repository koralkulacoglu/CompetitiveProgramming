class Solution {
    int score(string& s) {
        int n = s.size();
        int res = 0;
        for (int i=1; i<n; i++) {
            res += s[i] == s[i-1];
        }
        return res;
    }
public:
    int countRotations(string s, int k) {
        int ans = 0;
        int n = s.size();
        for (int i=0; i<n; i++) {
            ans += score(s) == k;
            s.push_back(s[0]);
            s = s.substr(1);
        }
        return ans;
    }
};
