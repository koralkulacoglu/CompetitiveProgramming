class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // find nodes with least amount of vectors pointing to it.
        map<int, int> mp;
        for (vector<int> i: edges) {
            mp[i[1]]++;
        }
        
        bool wk = false;
        int val = 1e9;
        int ans = 1e9;
        for (int i=0; i<n; i++) {
            if (mp[i] < ans) {
                ans = mp[i];
                wk = true;
                val = i;
            }
            else if (ans == mp[i]) {
                wk = false;
            }
        }
        
        if (!wk) return -1;
        return val;
    }
};
