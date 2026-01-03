class Solution {
public:
    int countCollisions(string d) {
        int n=d.size(), ans=n, l=0, r=0, s=0;
        for (auto &i : d) s += (i=='S');
        for (int i=0; i<n; i++) {
            if (d[i] != 'L') break;
            l++;
        }
        for (int i=n-1; i>=0; i--) {
            if (d[i] != 'R') break;
            r++;
        }
        return ans - l - r - s;
    }
};
