class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // nums1[i] will be there m times
        // nums2[i] will be there n times
        // check if odd or even then xor all of them

        int ans = 0;
        if (n%2) {
            for (int i : nums2) ans ^= i;
        }

        if (m%2) {
            for (int i : nums1) ans ^= i;
        }

        return ans;
    }
};


