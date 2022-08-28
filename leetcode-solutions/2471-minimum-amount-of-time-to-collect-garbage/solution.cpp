class Solution {
public:
    int cnt(string s, char c) {
        int res = 0;
        for (char i : s) res += i==c;
        return res;
    }
    int garbageCollection(vector<string>& s, vector<int>& travel) {
        int ans = 0;
        
        int n = s.size();
        int gw=0, pw=0, mw=0;
        int g=0, p=0, m=0;
        for (int i=0; i<n; i++) {
            int gc = cnt(s[i], 'G');
            int pc = cnt(s[i], 'P');
            int mc = cnt(s[i], 'M');
            
            if (gc) gw = i;
            if (pc) pw = i;
            if (mc) mw = i;
            
            g += gc;
            p += pc;
            m += mc;
        }
        vector<int> psa(n);
        psa[0] = 0;
        for (int i=1; i<n; i++) psa[i] = psa[i-1] + travel[i-1];
        
        ans = g + p + m;
        ans += psa[gw];
        ans += psa[pw];
        ans += psa[mw];
        
        return ans;
    }
};
