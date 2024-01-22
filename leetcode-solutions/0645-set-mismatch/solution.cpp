class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> xd(nums.begin(), nums.end());
        vector<int> lmao(xd.begin(), xd.end());
        int lolol=0;
        map<int, int> seen;
        for (int i : nums) {
            seen[i]++;
            if (seen[i] == 2) lolol = i;
        }
        int prev = 0;
        int n = lmao.size();
        for (int i=0; i<n; i++) {
            if (lmao[i] != prev+1) return {lolol, prev+1};
            prev++;
        }
        return {lolol, prev+1};
    }
};
