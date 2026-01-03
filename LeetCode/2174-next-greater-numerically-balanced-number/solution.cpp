class Solution {
public:
    bool isValid(int n) {
        vector<int> freq(10, 0);
        string s = to_string(n);
        for (char c : s) freq[c-'0']++;
        for (int i=0; i<10; i++) {
            if (freq[i] == 0) continue;
            if (i != freq[i]) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i=n+1; i<=n+1e6; i++) {
            if (isValid(i)) return i;
        }
        return -1;
    }
};
