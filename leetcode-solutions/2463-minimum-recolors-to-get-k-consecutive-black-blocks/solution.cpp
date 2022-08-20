class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black = 0, n = blocks.size();
        for (int i=0; i<k; i++) {
            black += blocks[i] == 'B';
        }
        int ans = k - black;
        for (int i=k; i<n; i++) {
            black += blocks[i] == 'B';
            black -= blocks[i-k] == 'B';
            ans = min(ans, k - black);
        }
        return ans;
    }
};
