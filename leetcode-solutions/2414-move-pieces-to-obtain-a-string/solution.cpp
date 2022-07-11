class Solution {
public:
    bool check(int r, int l) {
        if (r < 0) return false;
        if (l > 0) return false;
        if (r > 0 && l != 0) return false;
        if (l < 0 && r != 0) return false;
        return true;
    }
    
    bool canChange(string start, string target) {
        int n=start.size();
        int r=0, l=0;
        for (int i=0; i<n; i++) {
            r += start[i]=='R';
            l -= target[i]=='L';
                        
            if (!check(r, l)) {
                return false;
            }
            
            r -= target[i]=='R';
            l += start[i]=='L';

            if (!check(r, l)) {
                return false;
            }
        }
        if (r!=0 || l!=0) return false;
        return true;
    }
};
