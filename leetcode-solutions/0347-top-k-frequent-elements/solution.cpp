class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int i : nums) freq[i]++;

        set<pair<int, int>> pairs;
        for (auto i : freq) pairs.insert({-i.second, i.first});

        vector<int> ans(k);
        int i = 0;
        for (auto it=pairs.begin(); it!=pairs.end(); it++) {
            ans[i] = (*it).second;
            i++;
            if (i >= k) break;
        }

        return ans;
    }
};
