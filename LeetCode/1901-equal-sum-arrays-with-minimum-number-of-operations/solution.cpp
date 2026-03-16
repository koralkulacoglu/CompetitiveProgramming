class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m * 6 || m > n * 6) return -1;
        
        int sum1 = 0, sum2 = 0;
        for (int i : nums1) sum1 += i;
        for (int i : nums2) sum2 += i;

        if (sum1 > sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }

        int diff = sum2 - sum1;
        int ans = 0;

        vector<int> count(6, 0); 
        for (int x : nums1) count[6 - x]++;
        for (int x : nums2) count[x - 1]++;

        for (int i = 5; i > 0 && diff > 0; i--) {
            int take = min(count[i], (diff + i - 1) / i);
            ans += take;
            diff -= take * i;
        }

        return ans;
    }
};
