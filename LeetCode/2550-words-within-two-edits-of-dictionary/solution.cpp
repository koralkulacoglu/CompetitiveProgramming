class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for (string& s : queries) {
            int n = s.size();
            for (string& t : dictionary) {
                int d = 0;
                for (int i=0; i<n; i++) {
                    if (s[i] != t[i]) d++;
                    if (d > 2) break;
                }
                if (d <= 2) {
                    res.push_back(s);
                    break;
                }
            }
        }
        return res;
    }
};
