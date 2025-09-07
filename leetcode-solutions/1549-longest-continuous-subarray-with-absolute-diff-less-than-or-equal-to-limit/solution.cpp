class Solution {
public:
    int spread(multiset<int>& ms) {
        int minNum = *ms.begin();
        int maxNum = *ms.rbegin();

        return maxNum - minNum;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        multiset<int> ms;
        int ans = 1;
        int left = 0;
        for (int right=0; right<n; right++) {
            int num = nums[right];
            ms.insert(num);

            while (spread(ms) > limit) {
                int leftNum = nums[left];
                auto ptr = ms.find(leftNum);
                ms.erase(ptr);
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
