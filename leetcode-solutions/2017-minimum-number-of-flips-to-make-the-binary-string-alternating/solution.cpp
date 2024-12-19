class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string doubled = s + s;
        
        string pattern1, pattern2;
        for (int i = 0; i < 2 * n; ++i) {
            pattern1 += (i % 2 == 0 ? '0' : '1'); // "010101..."
            pattern2 += (i % 2 == 0 ? '1' : '0'); // "101010..."
        }
        
        int flips1 = 0, flips2 = 0, ans = n;
        
        for (int i = 0; i < n; ++i) {
            if (doubled[i] != pattern1[i]) flips1++;
            if (doubled[i] != pattern2[i]) flips2++;
        }
        ans = min(flips1, flips2);
        
        for (int i = n; i < 2 * n; ++i) {
            if (doubled[i - n] != pattern1[i - n]) flips1--;
            if (doubled[i - n] != pattern2[i - n]) flips2--;
            
            if (doubled[i] != pattern1[i]) flips1++;
            if (doubled[i] != pattern2[i]) flips2++;
            
            ans = min(ans, min(flips1, flips2));
        }
        
        return ans;
    }
};

