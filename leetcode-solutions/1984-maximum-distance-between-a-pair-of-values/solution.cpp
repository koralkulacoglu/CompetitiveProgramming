class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            auto ptr = upper_bound(nums2.begin()+i, nums2.end(), nums1[i], greater<int>());
            if (ptr == nums2.begin()+i) continue;
            int j = ptr - nums2.begin() - 1;
            ans = max(ans, j-i);
            // cout << i << ' ' << j << endl;
        }
        return ans;
    }
};
