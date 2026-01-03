class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), (long long)0);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), (long long)0);

        int zeros1 = count(nums1.begin(), nums1.end(), 0);
        int zeros2 = count(nums2.begin(), nums2.end(), 0);

        if (zeros1 == 0 && zeros2 == 0 && sum1 == sum2) return sum1;

        long long min1 = sum1 + zeros1;
        long long min2 = sum2 + zeros2;

        if (min1 > min2) {
            if (zeros2 == 0) return -1;
            return min1;
        }
        else {
            if (zeros1 == 0) return -1;
            return min2;
        }
    }
};
