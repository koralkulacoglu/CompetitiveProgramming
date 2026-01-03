class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int largest=0, smallest=0;
        for (int i=0; i<k; i++) {
            smallest += nums[i];
        }
        reverse(nums.begin(), nums.end());
        for (int i=0; i<k; i++) {
            largest += nums[i];
        }

        return largest - smallest;
    }
};
