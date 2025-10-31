class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);
        vector<int> res;

        for (int i : nums) {
            if (seen[i]) res.push_back(i);
            seen[i] = true;
        }

        return res;
    }
};
