class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> f1, f2;
        for (char i : word1) f1[i]++;
        for (char i : word2) f2[i]++;
        vector<int> v1, v2;
        for (auto i : f1) v1.push_back(i.second);
        for (auto i : f2) {
            if (!f1[i.first]) return false;
            v2.push_back(i.second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if (v1.size() != v2.size()) return false;
        for (int i=0; i<v1.size(); i++) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};
