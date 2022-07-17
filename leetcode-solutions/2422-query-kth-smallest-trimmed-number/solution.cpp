class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size(), m=nums[0].size();
        vector<int> res;
        for (vector<int> q : queries) {
            
            // 100^2 max
            vector<string> vals;
            for (int j=0; j<n; j++) {
                string st = nums[j].substr(m-q[1]);
                vals.push_back(st);
            }
            
            vector<string> nVals = vals;
            sort(vals.begin(), vals.end());

            // ~100 max
            int idx = q[0]-1;
            string val = vals[idx];
            int nth = 0;
            for (int j=idx; j>=0; j--) {
                if (val == vals[j]) {
                    nth++;
                }
                else {
                    break;
                }
            }

            // 100 max
            for (int j=0; j<n; j++) {
                if (nVals[j] == val) {
                    nth--;
                }
                if (nth == 0) {
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};
