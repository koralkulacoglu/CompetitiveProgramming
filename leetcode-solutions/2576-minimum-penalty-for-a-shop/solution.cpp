class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> psa(n); psa[n-1] = customers[n-1] == 'Y';
        for (int i=n-2; i>=0; i--) psa[i] = psa[i+1] + (customers[i] == 'Y');

        int ans = 0;
        int best = psa[0];
        int psaN = customers[0] == 'N';
        for (int i=1; i<=n; i++) {
            if (i == n) {
                int cur = psaN;
                if (cur < best) {
                    best = cur;
                    ans = i;
                }
                break;
            }
            
            int cur = psaN + psa[i];
            // cout << cur << ' ' << best << endl;
            if (cur < best) {
                best = cur;
                ans = i;
            }
            psaN += customers[i] == 'N';
        }

        return ans;
    }
};
