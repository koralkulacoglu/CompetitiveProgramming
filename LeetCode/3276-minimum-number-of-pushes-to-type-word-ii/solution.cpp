class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> freq; for (char i : word) freq[i]++;
        vector<int> vals; for (auto i : freq) vals.push_back(i.second);
        sort(vals.begin(), vals.end(), greater<int>());
        int cnt=8, ans=0;
        for (int i : vals) {
            ans += cnt/8*i;
            cnt++;
        }
        return ans;
    }
};
