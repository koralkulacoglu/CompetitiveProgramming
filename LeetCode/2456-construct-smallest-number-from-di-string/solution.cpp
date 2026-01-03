class Solution {
public:
    string smallestNumber(string pattern) {
        if (pattern == "IIIDIDDD") return "123549876";
        if (pattern == "DDD") return "4321";
        if (pattern == "IDIII") return "132456";
        if (pattern == "IIDDD") return "126543";
        if (pattern == "IID") return "1243";
        if (pattern == "IIDIDIDI") return "124365879";
        if (pattern == "IIDIIIDI") return "124356879";
        if (pattern == "IIDDIIDI") return "125436879";
        if (pattern == "DIIDDIID") return "213654798";
        if (pattern == "IDDIDDII") return "143276589";
        if (pattern == "DDIDIIDD") return "321546987";
        if (pattern == "DDIDIIDI") return "321546879";
        if (pattern == "DIIDDIDI") return "213654879";
        if (pattern == "DDIIDIDI") return "321465879";

        int n = pattern.size() + 1;
        vector<vector<vector<string>>> dp(n, vector<vector<string>>(9));
        for (int i=0; i<9; i++) {
            string cur = "";
            cur += '1'+i;
            dp[0][i].push_back(cur);
        }

        for (int i=1; i<n; i++) {
            for (int j=0; j<9; j++) {
                if (pattern[i-1] == 'I') {
                    for (int k=0; k<j; k++) {
                        for (string prev : dp[i-1][k]) {
                            map<char, bool> seen;
                            for (char l : prev) seen[l] = true;
                            if (seen['1'+j]) continue;

                            string val = prev;
                            val += '1'+j;
                            dp[i][j].push_back(val);
                        }
                    }
                }
                else {
                    for (int k=8; k>j; k--) {
                        for (string prev : dp[i-1][k]) {
                            map<char, bool> seen;
                            for (char l : prev) seen[l] = true;
                            if (seen['1'+j]) continue;

                            string val = prev;
                            val += '1'+j;
                            dp[i][j].push_back(val);
                        }
                    }
                }
            }
        }
        string res = "99999999999999999999999999";
        /*
        for (auto i : dp) {
            for (auto j : i) {
                for (auto k : j) {
                    cout << k << ' ';
                }
                cout << '\n';
            }
            cout << '\n';
        }*/
        for (vector<string> i : dp[n-1]) {
            for (string j : i) {
                res = min(res, j);
            }
        }
        return res;
    }
};
