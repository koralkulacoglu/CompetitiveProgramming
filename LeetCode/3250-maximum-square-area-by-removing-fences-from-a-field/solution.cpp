class Solution {
    int MOD = 1e9 + 7;
    
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        int h = hFences.size();
        int v = vFences.size();

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_map<int, bool> widths;
        for (int f1 : hFences) {
            for (int f2 : hFences) {
                if (f2 - f1 > 0) widths[f2 - f1] = true;
            }
        }

        long long ans = -1;
        for (int f1 : vFences) {
            for (int f2 : vFences) {
                long long dist = f2 - f1;
                if (widths[dist]) ans = max(ans, dist * dist);
            }
        }

        return ans % MOD;
    }
};
