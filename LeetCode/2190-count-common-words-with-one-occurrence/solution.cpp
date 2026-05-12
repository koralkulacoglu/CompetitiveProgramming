class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, pair<int, int>> freq;
        for (string& s : words1) freq[s].first++;
        for (string& s : words2) freq[s].second++;
        int ans = 0;
        for (auto& p : freq) ans += (p.second.first == 1 && p.second.second == 1);
        return ans;
    }
};
