class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        map<int, int> freq;
        multiset<int> counts;
        int ans = 0;
        for (int i=0; i<n; i++) {
            freq[nums[i]]++;
            counts.erase(freq[nums[i]]-1);
            counts.insert(freq[nums[i]]);
            while (*counts.rbegin() > k) {
                freq[nums[j]]--;
                counts.erase(freq[nums[j]]+1);
                counts.insert(freq[nums[i]]);
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};

