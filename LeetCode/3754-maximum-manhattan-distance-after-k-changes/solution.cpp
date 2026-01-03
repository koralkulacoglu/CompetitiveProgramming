class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int N=0, S=0, E=0, W=0;
        for (char c : s) {
            N += c == 'N';
            S += c == 'S';
            E += c == 'E';
            W += c == 'W';
            ans = max(ans, abs(N - S) + abs(E - W) + 2 * min(k, min(N, S) + min(E, W)));
        }
        return ans;
    }
};
