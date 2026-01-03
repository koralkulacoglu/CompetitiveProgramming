class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> nums;
        for (string i : ops) {
            int sz = nums.size();
            if (i == "+") nums.push_back(nums[sz-1] + nums[sz-2]);
            else if (i == "D") nums.push_back(nums[sz-1]*2);
            else if (i == "C") nums.pop_back();
            else nums.push_back(stoi(i));
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
