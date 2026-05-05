class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (nums[i]%2 != nums[j]%2) answer[i]++;
            }
        }
        return answer;
    }
};
