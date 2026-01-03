class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> rev(n, 0);
        for (int i=0; i<n; i++) {
            rev[edges[i]] += i;
        }
        long long ans = -1;
        int idx = 0;
        for (int i=0; i<n; i++) {
            if (rev[i] > ans) {
                ans = rev[i];
                idx = i;
            }
        }
        return idx;
    }
};
