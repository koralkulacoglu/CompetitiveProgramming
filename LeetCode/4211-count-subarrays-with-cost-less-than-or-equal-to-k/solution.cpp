class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        multiset<int> ms;
        int l = 0;
        long long ans = 0;
        for (int r=0; r<n; r++) {
            ms.insert(nums[r]);

            auto cost = [&]() {
                long long mn = *ms.begin();
                long long mx = *ms.rbegin();
                return (mx - mn) * (r - l + 1);
            };

            while (!ms.empty() && cost() > k) {
                auto it = ms.find(nums[l]);
                ms.erase(it);
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};
