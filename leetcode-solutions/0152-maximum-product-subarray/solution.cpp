class Solution {
public:
    int solve(vector<int> a) {
        int n=a.size();
        if (n == 0) return 0;
        if (n == 1) return a[0];
        int cnt=0; for (int &i : a) cnt += (i<0);
        if (cnt%2 == 0) {
            int ans=1;
            for (int &i : a) ans *= i;
            return ans;
        }
        else if (cnt == 1) {
            int ans1=1;
            for (int i=0; i<n; i++) {
                if (a[i]<0) break;
                ans1 *= a[i];
            }
            int ans2=1;
            for (int i=n-1; i>=0; i--) {
                if (a[i]<0) break;
                ans2 *= a[i];
            }
            return max(ans1, ans2);
        }
        else {
            int ans=1;
            for (int &i : a) ans *= i;
            int idx1=1;
            for (int i=0; i<n; i++) {
                if (a[i]<0) {
                    idx1 = i;
                    break;
                }
            }
            int idx2=1;
            for (int i=n-1; i>=0; i--) {
                if (a[i]<0) {
                    idx2 = i;
                    break;
                }
            }
            int ans1=1;
            for (int i=0; i<idx2; i++) {
                ans1 *= a[i];
            }
            int ans2=1;
            for (int i=n-1; i>idx1; i--) {
                ans2 *= a[i];
            }
            return max(ans1, ans2);
        }
    }
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> a;
        a.push_back({});
        int ans=-1e9;
        for (int &i : nums) {
            if (i == 0) {
                a.push_back({});
                continue;
            }
            a[a.size()-1].push_back(i);
        }
        for (vector<int> &b : a) {
            ans = max(ans, solve(b));
        }
        if (a.size() > 1) ans = max(ans, 0);
        return ans;
    }
};
