class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int i : nums) {
            if (i > 0) pos.push_back(i);
            else neg.push_back(i);
        }
        
        int n = nums.size();
        vector<int> res(n);
        for (int i=0; i<n; i++) {
            if (i%2) res[i] = neg[i/2];
            else res[i] = pos[i/2];
        }

        return res;
    }
};
