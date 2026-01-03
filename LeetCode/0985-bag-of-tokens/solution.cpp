class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int ans = 0;
        int j=n-1;
        for (int i=0; i<=j; i++) {
            if (tokens[i] <= power) {
                ans++;
                power -= tokens[i];
            }
            else if (i == j) break;
            else if (ans) {
                power += tokens[j] - tokens[i];
                j--;
            }
            // cout << power << ' ' << ans << '\n';
        }
        return ans;
    }
};
