class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0];
        });
        
        vector<int> dp; 
        for (vector<int> e : envelopes) {
            int s = e[1];
            auto it = lower_bound(dp.begin(), dp.end(), s);
            
            if (it == dp.end()) {
                dp.push_back(s);
            } else {
                *it = s;
            }
        }
        
        return dp.size();
    }
};
