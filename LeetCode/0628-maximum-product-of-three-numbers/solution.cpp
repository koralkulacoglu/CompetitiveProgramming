class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans = -1e9;
        sort(nums.begin(), nums.end());
        vector<int> rem = {nums[0], nums[1], nums[2]};
        if (nums.size() >= 4) rem.push_back(nums[nums.size()-1]);
        if (nums.size() >= 5) rem.push_back(nums[nums.size()-2]);
        if (nums.size() >= 6) rem.push_back(nums[nums.size()-3]);
        for (int i=0; i<pow(2, rem.size()); i++) {
            if (__builtin_popcount(i) == 3) {
                int sm = 1;
                for (int j=0; j<rem.size(); j++) {
                    if (i & (1<<(j))) {
                        sm *= rem[j];
                    }
                }
                ans = max(ans, sm);
            }
        }
        return ans;
    }
};
