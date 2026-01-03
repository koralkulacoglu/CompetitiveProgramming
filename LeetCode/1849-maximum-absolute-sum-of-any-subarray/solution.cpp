class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = 0, mn = 0, mxRes = 0, mnRes = 0;
        for (int i : nums) {
            mx = max(mx+i, i);
            mn = min(mn+i, i);
            mxRes = max(mxRes, mx);
            mnRes = min(mnRes, mn);
        }
        return max(abs(mxRes), abs(mnRes));
    }
};
