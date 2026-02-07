class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int allA = 0, both = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == 'a') allA++;
            else both = max(both + 1, allA + 1);
        }
        return n - max(allA, both);
    }
};
