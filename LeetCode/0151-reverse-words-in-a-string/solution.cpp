class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        vector<string> a;
        for (int i=0; i<n; i++) {
            if (s[i] == ' ') continue;

            string cur;
            while (i < n && s[i] != ' ') {
                cur.push_back(s[i]);
                i++;
            }
            a.push_back(cur);
        }

        reverse(a.begin(), a.end());

        string res;
        for (int i=0; i<a.size(); i++) {
            res += a[i] + (i == a.size()-1 ? "" : " ");
        }

        return res;
    }
};
