class Solution {
public:
     int modulo(long long a, long long b, long long n){
        long long x=1, y=a; 
        while (b > 0) {
            if (b%2 == 1) {
                x = (x*y) % n; // multiplying with base
            }
            y = (y*y) % n; // squaring the base
            b /= 2;
        }
        return x % n;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n = variables.size();
        vector<int> ans;
        for (int i=0; i<n; i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            if (modulo(modulo(a, b, 10), c, m) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

