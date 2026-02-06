class Solution {
public:
    string reverseByType(string s) {
        string a, b;
        for (char c : s) {
            if (islower(c)) a.push_back(c);
            else b.push_back(c);
        }

        int i=a.size()-1;
        int j=b.size()-1;
        int n = s.size();
        for (int k=0; k<n; k++) {
            if (islower(s[k])) {
                s[k] = a[i];
                i--;
            }
            else {
                s[k] = b[j];
                j--;
            }
        }
        
        return s;
    }
};
