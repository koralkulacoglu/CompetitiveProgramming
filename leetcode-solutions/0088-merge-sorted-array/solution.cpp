class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(n+m);
        int i = 0;
        int j = 0;
        int idx = 0;
        while (idx < n+m) {
            if (j >= n || i < m && nums1[i] < nums2[j]) {
                res[idx] = nums1[i];
                i++;
            }
            else {
                res[idx] = nums2[j];
                j++;
            }
            idx++;
        }

        nums1 = res;
    }
};
