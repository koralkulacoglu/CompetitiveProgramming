class Solution {
public:
    int n;
    vector<int> psa;
    mt19937 gen;
    
    Solution(vector<int>& w) {
        n = w.size();
        psa.clear();
        psa.push_back(w[0]);
        for (int i=1; i<n; i++) psa.push_back(w[i] + psa[i-1]);
    }
    
    int pickIndex() {
        uniform_int_distribution<int> dist(1, psa[n - 1]);
        int num = dist(gen);
        int res = lower_bound(psa.begin(), psa.end(), num) - psa.begin();
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
