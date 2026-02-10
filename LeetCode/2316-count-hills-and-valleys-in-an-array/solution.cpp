class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> vals;
        for (int i : nums) {
            if (vals.empty() || i != vals[vals.size()-1]) vals.push_back(i);
        }

        int ans = 0;
        int n = vals.size();
        for (int i=1; i<n-1; i++) {
            if (vals[i] >= vals[i-1] && vals[i] >= vals[i+1]) ans++;
            if (vals[i] <= vals[i-1] && vals[i] <= vals[i+1]) ans++;
        }
        
        return ans;
    }
};
