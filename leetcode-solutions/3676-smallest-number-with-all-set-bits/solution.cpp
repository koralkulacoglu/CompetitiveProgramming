class Solution {
public:
    vector<int> dp;
    int smallestNumber(int n) {
        if (dp.empty()) {
            dp.push_back(1);
            for (int i=0; i<32; i++) dp.push_back((dp[dp.size()-1] << 1) + 1);
        }

        for (int i : dp) {
            if (i >= n) return i;
        }
        return -1;
    }
};
