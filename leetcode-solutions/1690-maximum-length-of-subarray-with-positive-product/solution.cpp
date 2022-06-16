class Solution {
public:
    int solve(vector<int> a) {
        int n=a.size();
        int cnt=0; for (int &i : a) cnt += (i<0);
        if (cnt%2 == 0) {
            return n;
        }
        else if (cnt == 1) {
            for (int i=0; i<n; i++) {
                if (a[i] < 0) {
                    return max(i, n-i-1);
                }
            }
            return n;
        }
        else {
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
            int ans=idx1;
            ans = max(ans, n-idx2-1);
            ans = max(ans, idx2);
            ans = max(ans, n-idx1-1);
            return ans;
        }
    }
    int getMaxLen(vector<int>& nums) {
        vector<vector<int>> a;
        a.push_back({});
        int ans=0;
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
