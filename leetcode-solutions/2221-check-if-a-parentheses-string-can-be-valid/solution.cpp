class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size(), mn=0, mx=0;
        for (int i=0; i<n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    mn++;
                    mx++;
                }
                else {
                    mn--;
                    mx--;
                }
            }
            else {
                mn--;
                mx++;
            }
            if (mx < 0) return false;
        }
        if (!(n%2 == 0 && mn <= 0 && mx >= 0)) return false;

        mx = 0; mn = 0;
        for (int i=n-1; i>=0; i--) {
            if (locked[i] == '1') {
                if (s[i] == ')') {
                    mn++;
                    mx++;
                }
                else {
                    mn--;
                    mx--;
                }
            }
            else {
                mn--;
                mx++;
            }
            if (mx < 0) return false;
        }
        if (!(n%2 == 0 && mn <= 0 && mx >= 0)) return false;
        
        return true;
    }
};
