class Solution {
public:
    long long minimalKSum(vector<int>& lol, int k) {
        vector<long long> nums(lol.begin(), lol.end());

        nums.push_back(0);
        nums.push_back(1e18);
        sort(nums.begin(), nums.end());

        int n=nums.size();
        long long ans=0;
        bool bk=false;
        for (int i=0; i<n-1; i++) {
            long long diff = nums[i+1] - nums[i] - 1;
            if (diff <= 0) continue;
            
            if (diff >= k) {
                diff = k;
                bk = true;
            }
            // cout << diff << ' ' << diff*(nums[i]+1+nums[i]+diff)/2 << '\n';
            
            ans += diff*(nums[i]+1+nums[i]+diff)/2;

            k -= diff;
            
            if (bk) break;
        }
        return ans;
    }
};
