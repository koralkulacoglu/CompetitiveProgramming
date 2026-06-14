class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), ans = 0;
        unordered_map<string, int> freq;
        vector<int> window(26, 0);
        int letters = 0;
        for (int i = 0; i < n; i++) {
            window[s[i] - 'a']++;
            if (window[s[i] - 'a'] == 1) letters++;
            if (i >= minSize) {
                int j = s[i - minSize] - 'a';
                if (--window[j] == 0) letters--;
            }
            if (i >= minSize - 1 && letters <= maxLetters) ans = max(ans, ++freq[s.substr(i - minSize + 1, minSize)]);
        }
        return ans;
    }
};
