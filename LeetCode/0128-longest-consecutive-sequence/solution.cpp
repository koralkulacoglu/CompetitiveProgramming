class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        map<int, int> mp;
        for (int i : nums) {
            if (mp[i-1]) mp[i] = mp[i-1]+1;
            else mp[i] = 1;
            ans = max(ans, mp[i]);
        }

        return ans;
    }
};
