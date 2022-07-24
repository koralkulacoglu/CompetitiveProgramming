class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int ans=0, n=a.size();
        map<string, int> freq;
        for (int i=0; i<n; i++) {
            string cur="";
            for (int j=0; j<n; j++) {
                cur += to_string(a[i][j]) + ' ';
            }
            freq[cur]++;
        }
        for (int i=0; i<n; i++) {
            string cur="";
            for (int j=0; j<n; j++) {
                cur += to_string(a[j][i]) + ' ';
            }
            ans += freq[cur];
        }
        return ans;
    }
};
