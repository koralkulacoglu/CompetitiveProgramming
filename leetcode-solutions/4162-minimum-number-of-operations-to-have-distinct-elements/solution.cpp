class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int dup = 0;
        for (int i : nums) {
            if (freq[i] == 1) dup++;
            freq[i]++;
        }

        int ops = 0;
        if (dup == 0) return ops;
        for (int i=0; i<n; i+=3) {
            ops++;

            if (i < n) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 1) dup--;
            }
            
            if (i+1 < n) {
                freq[nums[i+1]]--;
                if (freq[nums[i+1]] == 1) dup--;
            }
            
            if (i+2 < n) {
                freq[nums[i+2]]--;
                if (freq[nums[i+2]] == 1) dup--;
            }

            if (dup <= 0) return ops;
        }

        return n/3;
    }
};
