class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++; 
        sort(nums.begin(), nums.end());
        
        for (int num : nums) {
            if (!freq[num]) continue;
            for (int i = 0; i < k; i++) {
                if (freq[num + i] == 0) return false;  // If the consecutive number is not available, return false
                freq[num + i]--;
            }
        }
        
        return true;
    }
};

