class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        map<char, int> firstIdx;
        map<char, int> lastIdx;

        for (char i='a'; i<='z'; i++) {
            firstIdx[i] = -1;
            lastIdx[i] = -1;
        }

        vector<vector<bool>> ans(26, vector<bool>(26, 0));
        for (int i=0; i<n; i++) {
            int first = firstIdx[s[i]];

            if (first == -1) {
                firstIdx[s[i]] = i;
                lastIdx[s[i]] = i;
                continue;
            }

            for (char j='a'; j<='z'; j++) {
                int last = lastIdx[j];

                if (last != -1 && first < last) {
                    ans[s[i]-'a'][j-'a'] = true;
                }
            }

            lastIdx[s[i]] = i;
        }

        int res = 0;
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                res += ans[i][j];
            }
        }

        return res;
    }
};
