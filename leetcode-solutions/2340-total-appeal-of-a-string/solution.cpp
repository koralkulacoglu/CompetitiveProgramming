class Solution {
public:
    long long appealSum(string s) {
        int n=s.size();
        long long ans=0;
        for (int i=0; i<n; i++) {
            ans += (long long)(i+1)*(i+2)/2;
        }
        
        long long sub = 0;
        map<char, long long> idx;
        for (int i=0; i<n; i++) {
            if (idx[s[i]]) {
                sub += (idx[s[i]]) * (n - i);
            }
            idx[s[i]] = i+1;
        }
        
        return ans - sub;
    }
};
