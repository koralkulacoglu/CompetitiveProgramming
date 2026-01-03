class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int> freq(27, 0);
        for (char c : s) freq[c - 'a']++;

        int ans = 0;
        for (int i : freq) ans += min(i, i%2 ? 1 : 2);

        return ans;
    }
};
