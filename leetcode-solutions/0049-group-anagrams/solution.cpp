class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for (string i : strs) {
            vector<int> freq(26, 0);
            for (char j : i) freq[j - 'a']++;
            mp[freq].push_back(i);
        }

        vector<vector<string>> res;
        for (auto i : mp) {
            res.push_back(i.second);
        }

        return res;
    }
};
