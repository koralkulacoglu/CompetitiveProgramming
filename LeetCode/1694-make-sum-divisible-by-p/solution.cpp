#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = 0;
        for (int x : nums) {
            totalSum = (totalSum + x) % p;
        }
        
        if (totalSum == 0) return 0; 

        unordered_map<int, int> sumIdxs;
        sumIdxs[0] = -1;
        long long curSum = 0;
        int ans = n;
        for (int i = 0; i < n; i++) {
            curSum = (curSum + nums[i]) % p;
            int needed = (curSum - totalSum + p) % p;
            if (sumIdxs.count(needed)) {
                ans = min(ans, i - sumIdxs[needed]);
            }
            sumIdxs[curSum] = i;
        }

        return ans < n ? ans : -1;
    }
};
