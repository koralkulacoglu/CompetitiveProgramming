class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        for (int bit=0; bit<=30; bit++) {
            vector<int> sub;
            for (int x : nums) {
                if ((x >> bit) & 1) {
                    if (sub.empty() || x > sub.back()) {
                        sub.push_back(x);
                    } else {
                        auto it = lower_bound(sub.begin(), sub.end(), x);
                        *it = x;
                    }
                }
            }
            
            ans = max(ans, (int)sub.size());
        }
        
        return ans;
    }
};
