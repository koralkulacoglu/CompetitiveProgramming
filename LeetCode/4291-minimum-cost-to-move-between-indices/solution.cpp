class Solution {
    int n;
    vector<int> nums;

    int dist(int x, int y) {
        return abs(nums[x] - nums[y]);
    }
    
    int closest(int x) {
        if (x == 0) return 1;
        if (x == n - 1) return n - 2;
        if (dist(x, x-1) > dist(x, x+1)) return x+1;
        return x-1;
    }
    
public:
    vector<int> minCost(vector<int>& nums_, vector<vector<int>>& queries) {
        nums = nums_;
        n = nums.size();
        
        vector<int> psa(n);
        psa[0] = 0;
        for (int x=1; x<n; x++) {
            psa[x] = psa[x-1];
            int y = closest(x-1);
            if (y == x) psa[x]++;
            else psa[x] += dist(x, x-1);
        }

        vector<int> psaB(n); psaB[n-1] = 0;
        for (int x=n-2; x>=0; x--) {
            psaB[x] = psaB[x+1];
            int y = closest(x+1);
            if (y == x) psaB[x]++;
            else psaB[x] += dist(x, x+1);
        }

        /*
        for (int i : psa) cout << i << ' ';
        cout << endl;
        for (int i : psaB) cout << i << ' ';
        cout << endl;
        */

        vector<int> ans;
        for (auto& q : queries) {
            int s = q[0];
            int f = q[1];

            if (s < f) ans.push_back(psa[f] - psa[s]);
            else ans.push_back(psaB[f] - psaB[s]);
        }

        return ans;
    }
};
