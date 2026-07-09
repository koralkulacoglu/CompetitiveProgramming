class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<bool, bool>> spec(26);
        for (char c : word) {
            if (isupper(c)) spec[c-'A'].second = true;
            else spec[c-'a'].first = true;
        }

        int ans = 0;
        for (int i=0; i<26; i++) {
            if (spec[i].first && spec[i].second) ans++;
        }

        return ans;
    }
};
