class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*max_element(nums.begin(), nums.end()), *min_element(nums.begin(), nums.end()));
    }
};
