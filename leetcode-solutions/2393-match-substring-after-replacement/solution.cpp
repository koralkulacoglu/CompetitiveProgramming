class Solution {
public:
    // some sort of rolling hash
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n=s.size(), m=sub.size();
        unordered_map<string, bool> conv;
        for (vector<char> &i : mappings) {
            string cur = ""; cur += i[0]; cur += i[1];
            conv[cur] = true;
        }
        int cnt=0;
        for (int i=0; i<n; i++) {
            string cur = ""; cur += sub[cnt]; cur += s[i];
            if (s[i] != sub[cnt] && !conv[cur]) {
                // string cur2 = ""; cur2 += sub[0]; cur2 += s[i];
                // cnt = (s[i] == sub[0] || conv[cur2]);
                i -= cnt;
                cnt = 0;
            }
            else {
                cnt++;
            }
            if (cnt == m) return true;
        }
        return false;
    }
};
