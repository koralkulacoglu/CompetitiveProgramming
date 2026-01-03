class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size(), sum=nums[0], prev=nums[0];
        for (int i=1; i<n; i++) {
            if (nums[i] == prev+1) {
                sum += nums[i];
            }
            else break;
            prev++;
        }
        sort(nums.begin(), nums.end());
        for (int i=sum; i<1e5; i++) {
            if (find(nums.begin(), nums.end(), i) == nums.end()) return i;
        }
        return sum;
    }
};
