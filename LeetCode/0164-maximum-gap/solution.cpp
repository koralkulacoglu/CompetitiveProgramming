class Solution {
    void radixSort(vector<int>& a) {
        if (a.empty()) return;
        for (int bit=0; bit<=30; bit++) {
            vector<int> zero, one;
            for (int i : a) {
                if ((i >> bit) & 1) {
                    one.push_back(i);
                } else {
                    zero.push_back(i);
                }
            }
            a.clear();
            for (int i : zero) a.push_back(i);
            for (int i : one) a.push_back(i);
        }
    }
public:
    int maximumGap(vector<int>& nums) {
        radixSort(nums);
        int n = nums.size();
        int ans = 0;
        for (int i=1; i<n; i++) ans = max(ans, abs(nums[i] - nums[i-1]));
        return ans;
    }
};
