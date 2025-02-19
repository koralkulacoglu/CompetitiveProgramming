class Solution {
public:
    bool check(string s) {
        int n = s.size();
        for (int i=0; i<n-1; i++) {
            if (s[i] == s[i+1]) return false;
        }
        return true;
    }

    string getHappyString(int n, int k) {
        vector<string> a;
        for (int i=0; i<pow(3, n); i++) {
            // convert number to string
            string cur;
            for (int j=0; j<n; j++) cur.push_back('a' + (int(i / pow(3, j)) % 3));

            if (check(cur)) a.push_back(cur);
        }

        sort(a.begin(), a.end());

        return k > a.size() ? "" : a[k-1];
    }
};

