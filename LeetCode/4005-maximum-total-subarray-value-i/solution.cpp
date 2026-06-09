class Solution {
public:
    long long maxTotalValue(vector<int>& nums, long long k) {
        return k * (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()));
    }
};
