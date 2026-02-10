class Solution {
public:
    int countCollisions(string d) {
        int ans = 0;
        int rights = 0;
        bool any = false;
        for (char c : d) {
            if (c == 'R') {
                rights++;
                any = true;
            }
            else if (c == 'L') {
                if (rights) ans += rights + 1;
                else if (any) ans++;
                rights = 0;
            }
            else {
                ans += rights;
                rights = 0;
                any = true;
            }
        }
        return ans;
    }
};
