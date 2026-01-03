class Solution {
public:
    vector<int> v;
    int x, y, z;
    bool good(int i, int j, int k) {
        if (abs(v[i] - v[j]) > x) return false;
        if (abs(v[j] - v[k]) > y) return false;
        if (abs(v[i] - v[k]) > z) return false;
        return true;
    }
    
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        v = arr;
        x = a, y = b, z = c;
        map<int, bool> seen;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    ans += good(i, j, k);
                }
            } 
        }

        return ans;
    }
};
