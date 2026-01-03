class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n);
        for (int i : nums) freq[i-1]++;
        vector<int> res(2);
        for (int i=0; i<n; i++) {
            if (freq[i] == 2) res[0] = i+1;
            if (freq[i] == 0) res[1] = i+1; 
        }
        return res;
    }
};
