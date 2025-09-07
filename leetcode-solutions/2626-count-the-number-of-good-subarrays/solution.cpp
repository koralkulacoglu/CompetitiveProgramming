class Solution {
public:
    long long pairs(long long n) {
        return n * (n - 1) / 2;
    }

    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long ans = 0;
        long long p = 0;
        int left = 0;
        for (int right=0; right<n; right++) {
            int num = nums[right];
            int f = freq[num];
            freq[num]++;

            p -= pairs(f);
            p += pairs(f + 1);

            while(p >= k) {
                ans += n - right;

                int leftNum = nums[left];
                int leftF = freq[leftNum];
                freq[leftNum]--;

                p -= pairs(leftF);
                p += pairs(leftF - 1);

                left++;
            }
        }

        return ans;
    }
};
