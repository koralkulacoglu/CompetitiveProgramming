class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> bIdx(26, -1), eIdx(26, -1);
        for (int i=0; i<n; i++) eIdx[s[i] - 'a'] = i;
        for (int i=n-1; i>=0; i--) bIdx[s[i] - 'a'] = i;

        vector<vector<int>> charContains(26, vector<int>(26, false));
        for (int i=0; i<26; i++) {
            if (bIdx[i] == -1) continue;

            for (int j=bIdx[i]; j<=eIdx[i]; j++) charContains[i][s[j] - 'a'] = true;
        }

        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                if (!charContains[j][i]) continue;
                for (int k=0; k<26; k++) charContains[j][k] |= charContains[i][k];
            }
        }

        for (int i=0; i<26; i++) {
            if (bIdx[i] == -1) continue;
            for (int j=0; j<26; j++) {
                if (bIdx[j] == -1) continue;
                if (!charContains[i][j]) continue;

                bIdx[i] = min(bIdx[i], bIdx[j]);
                eIdx[i] = max(eIdx[i], eIdx[j]);
            }
        }

        vector<int> dp(n);
        dp[0] = eIdx[s[0] - 'a'] == 0;
        for (int i=1; i<n; i++) {
            dp[i] = dp[i-1];

            int b = bIdx[s[i] - 'a'];
            int e = eIdx[s[i] - 'a'];

            if (i != e) continue;

            if (b > 0) dp[i] = max(dp[i], dp[b - 1] + 1);
            else dp[i] = max(dp[i], 1);
        }

        /*
        for (int i=0; i<26; i++) {
            if (bIdx[i] == -1) continue;
            char c = 'a' + i;
            cout << c << ": " << bIdx[i] << " - " << eIdx[i] << endl;
        }

        for (int i : dp) cout << i << ' ';
        cout << endl;
        */

        vector<string> res;
        int idx = n-1;
        while (idx > 0) {
            if (dp[idx] != dp[idx-1] + 1) {
                idx--;
            }
            else {
                int b = bIdx[s[idx] - 'a'];
                string cur = s.substr(b, idx - b + 1);
                res.push_back(cur);
                idx = b - 1;
            }
        }

        if (dp[0] == 1) {
            string extra; extra += s[0];
            res.push_back(extra);
        }

        return res;
    }
};
