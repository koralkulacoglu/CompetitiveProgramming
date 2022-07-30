class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<string, int> ord;
        int n=nums.size(), j=0;
        for (int i=0; i<n; i++) {
            string vals = "";
            int divs=0;
            for (int j=i; j<n; j++) {
                vals += to_string(nums[j]) + " ";
                divs += (nums[j]%p == 0);
                if (divs > k) break;
                ord[vals] = true;
            }
        }
        return ord.size();
    }
};
